#include <PnC/DracoPnC/TestSet/TestSet.hpp>
#include <PnC/DracoPnC/CtrlSet/CtrlSet.hpp>
#include <PnC/DracoPnC/ContactSet/ContactSet.hpp>
#include <PnC/DracoPnC/DracoDefinition.hpp>
#include <PnC/DracoPnC/DracoInterface.hpp>
#include <PnC/DracoPnC/DracoStateProvider.hpp>
#include <PnC/DracoPnC/TaskSet/TaskSet.hpp>
#include <PnC/WBC/IHWBC/IHWBC.hpp>
#include <PnC/MPC/CMPC.hpp>
#include <Utils/IO/DataManager.hpp>
#include <Utils/Math/MathUtilities.hpp>
#include <Utils/Math/hermite_curve_vec.hpp>
#include <Utils/Math/hermite_quaternion_curve.hpp>
#include <PnC/DracoPnC/PredictionModule/DCMWalkingReferenceTrajectoryModule.hpp>

SingleSupportCtrl::SingleSupportCtrl(RobotSystem* robot,
        WalkingReferenceTrajectoryModule* walking_module) : Controller(robot) {
    myUtils::pretty_constructor(2, "Single Support Ctrl");

    walking_reference_trajectory_module_ = walking_module;

    tau_cmd_ = Eigen::VectorXd::Zero(Draco::n_adof);
    tau_cmd_old_ = Eigen::VectorXd::Zero(Draco::n_adof);
    qddot_cmd_ = Eigen::VectorXd::Zero(Draco::n_adof);

    // Tasks
    com_task_ = new BasicTask(robot_, BasicTaskType::COM, 3);
    bodyori_task_ = new BasicTask(robot_, BasicTaskType::LINKORI, 3, DracoBodyNode::Torso);
    rfoot_front_task_ = new BasicTask(robot_, BasicTaskType::LINKXYZ, 3, DracoBodyNode::rFootFront);
    rfoot_back_task_ = new BasicTask(robot_, BasicTaskType::LINKXYZ, 3, DracoBodyNode::rFootBack);
    lfoot_front_task_ = new BasicTask(robot_, BasicTaskType::LINKXYZ, 3, DracoBodyNode::lFootFront);
    lfoot_back_task_ = new BasicTask(robot_, BasicTaskType::LINKXYZ, 3, DracoBodyNode::lFootBack);
    rfoot_line_task_ = new LineFootTask(robot_, DracoBodyNode::rFootCenter);
    lfoot_line_task_ = new LineFootTask(robot_, DracoBodyNode::lFootCenter);

    // Contacts
    rfoot_front_contact_ = new PointContactSpec(robot_, DracoBodyNode::rFootFront, 0.7);
    rfoot_back_contact_ = new PointContactSpec(robot_, DracoBodyNode::rFootBack, 0.7);
    lfoot_front_contact_ = new PointContactSpec(robot_, DracoBodyNode::lFootFront, 0.7);
    lfoot_back_contact_ = new PointContactSpec(robot_, DracoBodyNode::lFootBack, 0.7);

    dim_contact_ = rfoot_front_contact_->getDim() + lfoot_front_contact_->getDim() +
                   rfoot_back_contact_->getDim() + lfoot_back_contact_->getDim();

    // IHWBC
    std::vector<bool> act_list;
    act_list.resize(robot_->getNumDofs(), true);
    for (int i(0); i < robot_->getNumVirtualDofs(); ++i) act_list[i] = false;
    ihwbc_ = new IHWBC(act_list);

    sp_ = DracoStateProvider::getStateProvider(robot_);
}

SingleSupportCtrl::~SingleSupportCtrl() {
    // Tasks
    delete com_task_;
    delete bodyori_task_;
    delete rfoot_front_task_;
    delete rfoot_back_task_;
    delete lfoot_front_task_;
    delete lfoot_back_task_;
    delete rfoot_line_task_;
    delete lfoot_line_task_;

    // Contacts
    delete rfoot_front_contact_;
    delete rfoot_back_contact_;
    delete lfoot_front_contact_;
    delete lfoot_back_contact_;

    // IHWBC
    delete ihwbc_;
}

void SingleSupportCtrl::firstVisit() {
    std::cout << "[[Single Support Phase]]" << std::endl;
    ctrl_start_time_ = sp_->curr_time;
    //_compute_swing_foot_trajectory_spline();
    _compute_swing_foot_trajectory_hermite();

    if (sp_->num_residual_steps == -1) {
        sp_->b_walking = false;
    }
}

void SingleSupportCtrl::lastVisit() {
}

bool SingleSupportCtrl::endOfPhase() {
    if (state_machine_time_ > end_time_) {
        return true;
    }
    if (sp_->phase_copy == static_cast<int>(
                DCMPhaseWalkingTestPhase::DCMPhaseWalkingTestPhase_left_swing_ctrl)) {
         //right stance, left swing
        if ((state_machine_time_ > 0.5*end_time_ && sp_->b_lfoot_contact)) {
            return true;
        }
    } else {
         //left stance, right swing
        if ((state_machine_time_ > 0.5*end_time_ && sp_->b_rfoot_contact)) {
            return true;
        }
    }

    return false;
}

void SingleSupportCtrl::_compute_swing_foot_trajectory_spline(){
    double ini[9];
    double fin[9];
    double** middle_pt = new double*[1];
    middle_pt[0] = new double[3];
    Eigen::VectorXd ini_pos;
    Eigen::VectorXd fin_pos = sp_->swing_foot_target_pos;
    Eigen::Quaternion<double> ini_quat;
    Eigen::Quaternion<double> fin_quat = sp_->swing_foot_target_quat;

    if (sp_->phase_copy == static_cast<int>(
                DCMPhaseWalkingTestPhase::DCMPhaseWalkingTestPhase_left_swing_ctrl)) {
        // right stance, left swing
    ini_pos = robot_->getBodyNodeIsometry(
            DracoBodyNode::lFootCenter).translation();
    ini_quat = Eigen::Quaternion<double>(
            robot_->getBodyNodeIsometry(DracoBodyNode::lFootCenter).linear());

    } else {
        // left stance, right swing
    ini_pos = robot_->getBodyNodeIsometry(
            DracoBodyNode::rFootCenter).translation();
    ini_quat = Eigen::Quaternion<double>(
            robot_->getBodyNodeIsometry(DracoBodyNode::rFootCenter).linear());
    }

    for (int i = 0; i < 3; ++i) {
        ini[i] = ini_pos[i];
        ini[i+3] = 0.;
        ini[i+6] = 0.;
        fin[i] = fin_pos[i];
        // TODO : Should find proper number for this in Experiment
        fin[i+3] = 0.;
        fin[i+6] = 0.;
    }
    for (int i = 0; i < 2; ++i) {
        middle_pt[0][i] = (ini_pos[i] + fin_pos[i])/2.0;
    }
    middle_pt[0][2] = swing_height_;
    foot_pos_spline_traj_.SetParam(ini, fin, middle_pt, end_time_);

    delete[] * middle_pt;
    delete[] middle_pt;

    foot_ori_trajectory_.reset(new HermiteQuaternionCurve(ini_quat,
                Eigen::Vector3d::Zero(3), fin_quat, Eigen::Vector3d::Zero(3)));
}

void SingleSupportCtrl::_compute_swing_foot_trajectory_hermite(){
    Eigen::VectorXd ini_pos;
    Eigen::VectorXd fin_pos = sp_->swing_foot_target_pos;
    Eigen::Quaternion<double> ini_quat;
    Eigen::Quaternion<double> fin_quat = sp_->swing_foot_target_quat;

    if (sp_->phase_copy == static_cast<int>(
                DCMPhaseWalkingTestPhase::DCMPhaseWalkingTestPhase_left_swing_ctrl)) {
        // right stance, left swing
    ini_pos = robot_->getBodyNodeIsometry(
            DracoBodyNode::lFootCenter).translation();
    ini_quat = Eigen::Quaternion<double>(
            robot_->getBodyNodeIsometry(DracoBodyNode::lFootCenter).linear());

    } else {
        // left stance, right swing
    ini_pos = robot_->getBodyNodeIsometry(
            DracoBodyNode::rFootCenter).translation();
    ini_quat = Eigen::Quaternion<double>(
            robot_->getBodyNodeIsometry(DracoBodyNode::rFootCenter).linear());
    }

    //myUtils::pretty_print(ini_pos, std::cout, "foot ini pos");
    //myUtils::pretty_print(fin_pos, std::cout, "foot fin pos");

    Eigen::VectorXd mid_pos= (ini_pos + fin_pos) / 2.0;
    Eigen::VectorXd mid_vel = (fin_pos - ini_pos) / end_time_;
    mid_pos[2] = swing_height_;
    foot_pos_traj_init_to_mid_.reset(new HermiteCurveVec(ini_pos,
                Eigen::Vector3d::Zero(3), mid_pos, mid_vel));
    foot_pos_traj_mid_to_end_.reset(new HermiteCurveVec(mid_pos, mid_vel,
                fin_pos, Eigen::Vector3d::Zero(3)));
    foot_ori_trajectory_.reset(new HermiteQuaternionCurve(ini_quat,
                Eigen::Vector3d::Zero(3), fin_quat, Eigen::Vector3d::Zero(3)));
}

void SingleSupportCtrl::ctrlInitialization(const YAML::Node& node) {
    myUtils::readParameter(node, "max_fz", max_fz_);

    // Task Weights
    myUtils::readParameter(node, "com_task_weight", com_task_weight_);
    myUtils::readParameter(node, "bodyori_task_weight", bodyori_task_weight_);
    myUtils::readParameter(node, "rfoot_task_weight", rfoot_task_weight_);
    myUtils::readParameter(node, "lfoot_task_weight", lfoot_task_weight_);
    myUtils::readParameter(node, "rf_tracking_weight", rf_tracking_weight_);
    myUtils::readParameter(node, "qddot_reg_weight", qddot_reg_weight_);
    myUtils::readParameter(node, "rf_reg_weight", rf_reg_weight_);

    // Task Gains
    Eigen::VectorXd kp, kd;

    myUtils::readParameter(node, "com_task_kp_gain", kp);
    myUtils::readParameter(node, "com_task_kd_gain", kd);
    com_task_->setGain(kp, kd);

    myUtils::readParameter(node, "bodyori_task_kp_gain", kp);
    myUtils::readParameter(node, "bodyori_task_kd_gain", kd);
    bodyori_task_->setGain(kp, kd);

    myUtils::readParameter(node, "rfoot_task_kp_gain", kp);
    myUtils::readParameter(node, "rfoot_task_kd_gain", kd);
    rfoot_front_task_->setGain(kp, kd);
    rfoot_back_task_->setGain(kp, kd);

    myUtils::readParameter(node, "lfoot_task_kp_gain", kp);
    myUtils::readParameter(node, "lfoot_task_kd_gain", kd);
    lfoot_front_task_->setGain(kp, kd);
    lfoot_back_task_->setGain(kp, kd);

    myUtils::readParameter(node, "lfoot_line_task_kp_gain", kp);
    myUtils::readParameter(node, "lfoot_line_task_kd_gain", kd);
    lfoot_line_task_->setGain(kp, kd);

    myUtils::readParameter(node, "rfoot_line_task_kp_gain", kp);
    myUtils::readParameter(node, "rfoot_line_task_kd_gain", kd);
    rfoot_line_task_->setGain(kp, kd);

    // Safety Parameters on Admittance Control
    myUtils::readParameter(node, "velocity_break_freq", velocity_break_freq_);
    myUtils::readParameter(node, "position_break_freq", position_break_freq_);
    myUtils::readParameter(node, "max_jvel", max_jvel_);
    myUtils::readParameter(node, "max_jpos_error", max_jpos_error_);
}

void SingleSupportCtrl::oneStep(void* _cmd) {
    _PreProcessing_Command();
    state_machine_time_ = sp_->curr_time - ctrl_start_time_;

    _contact_setup();
    _task_setup();
    _compute_torque_ihwbc();

    double alphaTau = (1.0 - myUtils::computeAlphaGivenBreakFrequency(
                100.0, DracoAux::ServoRate));
    tau_cmd_old_ = tau_cmd_*alphaTau + (1.0 - alphaTau)*tau_cmd_old_;

    for (int i(0); i < robot_->getNumActuatedDofs(); ++i) {
        ((DracoCommand*)_cmd)->jtrq[i] = tau_cmd_old_[i];
        ((DracoCommand*)_cmd)->q[i] = sp_->des_jpos[i];
        ((DracoCommand*)_cmd)->qdot[i] = sp_->des_jvel[i];
    }

    _PostProcessing_Command();
}

void SingleSupportCtrl::_contact_setup() {
    rfoot_front_contact_->updateContactSpec();
    rfoot_back_contact_->updateContactSpec();
    lfoot_front_contact_->updateContactSpec();
    lfoot_back_contact_->updateContactSpec();

    contact_list_.push_back(rfoot_front_contact_);
    contact_list_.push_back(rfoot_back_contact_);
    contact_list_.push_back(lfoot_front_contact_);
    contact_list_.push_back(lfoot_back_contact_);

    if (sp_->phase_copy == static_cast<int>(
                DCMPhaseWalkingTestPhase::DCMPhaseWalkingTestPhase_left_swing_ctrl)) {
        // right stance, left swing
        for (int i = 0; i < 2; ++i) {
            ((PointContactSpec*)contact_list_[i])->setMaxFz(max_fz_); // right foot
            ((PointContactSpec*)contact_list_[i+2])->setMaxFz(0.); // left foot
        }
    } else {
        // left stance, right swing
        for (int i = 0; i < 2; ++i) {
            ((PointContactSpec*)contact_list_[i])->setMaxFz(0.); // right foot
            ((PointContactSpec*)contact_list_[i+2])->setMaxFz(max_fz_); // left foot
        }
    }
}

void SingleSupportCtrl::_task_setup() {
    // CoM Task
    Eigen::VectorXd com_pos_des = Eigen::VectorXd::Zero(3);
    Eigen::VectorXd com_vel_des = Eigen::VectorXd::Zero(3);
    Eigen::VectorXd com_acc_des = Eigen::VectorXd::Zero(3);

    Eigen::Vector3d com_pos_ref, com_vel_ref, com_pos, com_vel;
    walking_reference_trajectory_module_->getMPCRefComPosandVel(
            sp_->curr_time, com_pos_ref, com_vel_ref);
    ((DCMWalkingReferenceTrajectoryModule*)walking_reference_trajectory_module_)->
        dcm_reference.get_ref_dcm(sp_->curr_time, sp_->dcm_des);
    ((DCMWalkingReferenceTrajectoryModule*)walking_reference_trajectory_module_)->
        dcm_reference.get_ref_dcm_vel(sp_->curr_time, sp_->dcm_vel_des);
    ((DCMWalkingReferenceTrajectoryModule*)walking_reference_trajectory_module_)->
        dcm_reference.get_ref_r_vrp(sp_->curr_time, sp_->r_vrp_des);

    com_pos = robot_->getCoMPosition();
    com_vel = robot_->getCoMVelocity();

    for (int i = 0; i < 2; ++i) {
        com_pos_des[i] = com_pos[i];
        com_vel_des[i] = com_vel[i];
    }
    Eigen::VectorXd r_ic = sp_->dcm.head(2);
    Eigen::VectorXd r_id = sp_->dcm_des.head(2);
    Eigen::VectorXd rdot_id = sp_->dcm_vel_des.head(2);
    Eigen::VectorXd r_icp_error = (r_ic - r_id);
    double kp_ic(20.);
    double omega_o = std::sqrt(9.81/target_com_height_);
    Eigen::VectorXd r_CMP_d = r_ic - rdot_id/omega_o + kp_ic * (r_icp_error);
    com_acc_des.head(2) = (9.81/target_com_height_) * (com_pos.head(2) - r_CMP_d);

    com_pos_des[2] = target_com_height_;
    com_vel_des[2] = com_vel_ref[2];
    com_acc_des[2] = 0.;

    com_task_->updateTask(com_pos_des, com_vel_des, com_acc_des);

    // BodyOri Task
    Eigen::VectorXd bodyori_pos_des = Eigen::VectorXd::Zero(4);
    Eigen::VectorXd bodyori_vel_des = Eigen::VectorXd::Zero(3);
    Eigen::VectorXd bodyori_acc_des = Eigen::VectorXd::Zero(3);

    Eigen::Quaterniond ori_ref;
    Eigen::Vector3d ang_vel_ref, ang_acc_ref;
    walking_reference_trajectory_module_->getMPCRefQuatAngVelAngAcc(sp_->curr_time,
            ori_ref, ang_vel_ref, ang_acc_ref);
    bodyori_pos_des << ori_ref.w(), ori_ref.x(), ori_ref.y(), ori_ref.z();
    for (int i = 0; i < 3; ++i) {
        bodyori_vel_des[i] = ang_vel_ref[i];
        bodyori_acc_des[i] = ang_acc_ref[i];
        //bodyori_acc_des[i] = 0.;
    }
    bodyori_task_->updateTask(
            bodyori_pos_des, bodyori_vel_des, bodyori_acc_des);

    // Point Foot Task
    Eigen::VectorXd zero_vec = Eigen::VectorXd::Zero(3);
    Eigen::VectorXd rfoot_front_pos =
        robot_->getBodyNodeCoMIsometry(DracoBodyNode::rFootFront).translation();
    Eigen::VectorXd rfoot_back_pos =
        robot_->getBodyNodeCoMIsometry(DracoBodyNode::rFootBack).translation();
    Eigen::VectorXd lfoot_front_pos =
        robot_->getBodyNodeCoMIsometry(DracoBodyNode::lFootFront).translation();
    Eigen::VectorXd lfoot_back_pos =
        robot_->getBodyNodeCoMIsometry(DracoBodyNode::lFootBack).translation();
    rfoot_front_task_->updateTask(rfoot_front_pos, zero_vec, zero_vec);
    rfoot_back_task_->updateTask(rfoot_back_pos, zero_vec, zero_vec);
    lfoot_front_task_->updateTask(lfoot_front_pos, zero_vec, zero_vec);
    lfoot_back_task_->updateTask(lfoot_back_pos, zero_vec, zero_vec);

    // Line Foot Task
    Eigen::Vector3d swing_foot_pos_des, swing_foot_vel_des, swing_foot_acc_des;
    Eigen::Quaternion<double> swing_foot_quat_des;
    Eigen::Vector3d swing_foot_ang_vel_des, swing_foot_ang_acc_des;

    double s(state_machine_time_ / end_time_);
    foot_ori_trajectory_->evaluate(s, swing_foot_quat_des);
    foot_ori_trajectory_->getAngularVelocity(s, swing_foot_ang_vel_des);
    foot_ori_trajectory_->getAngularAcceleration(s, swing_foot_ang_acc_des);
    if (state_machine_time_ < 0.5 * end_time_) {
        s = 2 * state_machine_time_ / end_time_;
        swing_foot_pos_des = foot_pos_traj_init_to_mid_->evaluate(s);
        swing_foot_vel_des = foot_pos_traj_init_to_mid_->evaluateFirstDerivative(s);
        swing_foot_acc_des = foot_pos_traj_init_to_mid_->evaluateSecondDerivative(s);
    } else {
        foot_pos_traj_mid_to_end_;
        s = 2 * (state_machine_time_ / end_time_ - 0.5);
        swing_foot_pos_des = foot_pos_traj_mid_to_end_->evaluate(s);
        swing_foot_vel_des = foot_pos_traj_mid_to_end_->evaluateFirstDerivative(s);
        swing_foot_acc_des = foot_pos_traj_mid_to_end_->evaluateSecondDerivative(s);
    }

    Eigen::VectorXd swing_foot_pos_task_des(7);
    Eigen::VectorXd swing_foot_vel_task_des(6);
    Eigen::VectorXd swing_foot_acc_task_des(6);
    swing_foot_pos_task_des << swing_foot_quat_des.w(), swing_foot_quat_des.x(),
                            swing_foot_quat_des.y(), swing_foot_quat_des.z(),
                            swing_foot_pos_des[0], swing_foot_pos_des[1],
                            swing_foot_pos_des[2];
    for (int i = 0; i < 3; ++i) {
        swing_foot_vel_task_des[i] = swing_foot_ang_vel_des[i];
        swing_foot_vel_task_des[i+3] = swing_foot_vel_des[i];
        swing_foot_acc_task_des[i] = swing_foot_ang_acc_des[i];
        swing_foot_acc_task_des[i+3] = swing_foot_acc_des[i];
    }

    if (sp_->phase_copy == static_cast<int>(
                DCMPhaseWalkingTestPhase::DCMPhaseWalkingTestPhase_left_swing_ctrl)) {
        // right stance, left swing
        lfoot_line_task_->updateTask(swing_foot_pos_task_des,
                swing_foot_vel_task_des, swing_foot_acc_task_des);
    } else {
        // left stance, right swing
        rfoot_line_task_->updateTask(swing_foot_pos_task_des,
                swing_foot_vel_task_des, swing_foot_acc_task_des);
    }

    //myUtils::pretty_print(swing_foot_pos_task_des, std::cout, "foot_task_pos");

    // Update Task List
    task_list_.push_back(com_task_);
    task_list_.push_back(bodyori_task_);

    if (sp_->phase_copy == static_cast<int>(
                DCMPhaseWalkingTestPhase::DCMPhaseWalkingTestPhase_left_swing_ctrl)) {
        // right stance, left swing
        task_list_.push_back(lfoot_line_task_);
        task_list_.push_back(rfoot_front_task_);
        task_list_.push_back(rfoot_back_task_);
    } else {
        // left stance, right swing
        task_list_.push_back(rfoot_line_task_);
        task_list_.push_back(lfoot_front_task_);
        task_list_.push_back(lfoot_back_task_);
    }

    // Task Weights
    task_weight_heirarchy_ = Eigen::VectorXd::Zero(task_list_.size());
    task_weight_heirarchy_[0] = com_task_weight_;
    task_weight_heirarchy_[1] = bodyori_task_weight_;
    if (sp_->phase_copy == static_cast<int>(
                DCMPhaseWalkingTestPhase::DCMPhaseWalkingTestPhase_left_swing_ctrl)) {
        // right stance, left swing
        task_weight_heirarchy_[2] = 1e-2; //left swing
        task_weight_heirarchy_[3] = rfoot_task_weight_;
        task_weight_heirarchy_[4] = rfoot_task_weight_;
    } else {
        // left stance, right swing
        task_weight_heirarchy_[2] = 1e-2; //right swing
        task_weight_heirarchy_[3] = lfoot_task_weight_;
        task_weight_heirarchy_[4] = lfoot_task_weight_;
    }
}

void SingleSupportCtrl::_compute_torque_ihwbc() {
    // Update Setting
    Eigen::MatrixXd A_rotor = A_;
    for (int i = 0; i < Draco::n_adof; ++i) {
        A_rotor(i + Draco::n_vdof, i + Draco::n_vdof) += sp_->rotor_inertia[i];
    }
    Eigen::MatrixXd A_rotor_inv = A_rotor.inverse();
    ihwbc_->updateSetting(A_rotor, A_rotor_inv, coriolis_, grav_);

    // Enable Torque Limits
    ihwbc_->enableTorqueLimits(true);
    ihwbc_->setTorqueLimits(-100*Eigen::VectorXd::Ones(Draco::n_adof),
            100*Eigen::VectorXd::Ones(Draco::n_adof));

    // Set QP Weights
    ihwbc_->setQPWeights(task_weight_heirarchy_,
            rf_tracking_weight_/robot_->getRobotMass()*9.81);
    ihwbc_->setRegularizationTerms(qddot_reg_weight_, rf_reg_weight_);

    // Solve
    ihwbc_->solve(task_list_, contact_list_, Eigen::VectorXd::Zero(dim_contact_),
            tau_cmd_, qddot_cmd_);
    ihwbc_->getQddotResult(sp_->qddot_cmd);
    ihwbc_->getFrResult(sp_->reaction_forces);

    // Integrate Joint Velocities
    Eigen::VectorXd qdot_des_ref = Eigen::VectorXd::Zero(Draco::n_adof);
    double alphaVelocity = myUtils::computeAlphaGivenBreakFrequency(
            velocity_break_freq_, DracoAux::ServoRate);
    sp_->des_jvel = sp_->des_jvel*alphaVelocity + (1. - alphaVelocity)*qdot_des_ref;
    sp_->des_jvel += (qddot_cmd_ * DracoAux::ServoRate);
    for (int i = 0; i < sp_->des_jvel.size(); ++i) {
        sp_->des_jvel[i] = myUtils::CropValue(sp_->des_jvel[i], -max_jvel_, max_jvel_);
    }

    // Integrate Joint Positions
    Eigen::VectorXd q_des_ref = sp_->q.tail(Draco::n_adof);
    double alphaPosition = myUtils::computeAlphaGivenBreakFrequency(
            position_break_freq_, DracoAux::ServoRate);
    sp_->des_jpos = sp_->des_jpos*alphaPosition + (1.0 - alphaPosition)*q_des_ref;
    sp_->des_jpos += (sp_->des_jvel*DracoAux::ServoRate);
    for (int i = 0; i < sp_->des_jpos.size(); ++i) {
        sp_->des_jpos[i] = myUtils::CropValue(sp_->des_jpos[i],
                q_des_ref[i]-max_jpos_error_, q_des_ref[i]+max_jpos_error_);
    }
}
