#include <Configuration.h>
#include <PnC/DracoPnC/DracoDefinition.hpp>
#include <PnC/DracoPnC/TaskSet/TaskSet.hpp>
#include <Utils/IO/IOUtilities.hpp>

LineFootTask::LineFootTask(RobotSystem* robot, int _link_idx) : Task(robot, 5) {
    myUtils::pretty_constructor(3, "Line Foot Task");

    Jt_ = Eigen::MatrixXd::Zero(dim_task_, robot_->getNumDofs());
    JtDotQdot_ = Eigen::VectorXd::Zero(dim_task_);
    link_idx_ = _link_idx;
}

LineFootTask::~LineFootTask() {}

bool LineFootTask::_UpdateCommand(const Eigen::VectorXd& _pos_des,
                                  const Eigen::VectorXd& _vel_des,
                                  const Eigen::VectorXd& _acc_des) {
    Eigen::Quaternion<double> des_ori(_pos_des[0], _pos_des[1], _pos_des[2],
                                      _pos_des[3]);
    Eigen::Quaternion<double> ori_act(
        robot_->getBodyNodeIsometry(link_idx_).linear());
    Eigen::Quaternion<double> quat_ori_err = des_ori * ori_act.inverse();
    Eigen::Vector3d ori_err_so3 = dart::math::quatToExp(quat_ori_err);

    // (Ry, Rz)
    for (int i = 0; i < 2; ++i) {
        // pos_err[i] = myUtils::bind_half_pi(ori_err_so3[i]);
        pos_err[i] = (ori_err_so3[i + 1]);
        vel_des[i] = _vel_des[i + 1];
        acc_des[i] = _acc_des[i + 1];
    }
    // (x, y, z)
    Eigen::VectorXd pos_act =
        robot_->getBodyNodeIsometry(link_idx_).translation();
    for (int i = 0; i < 3; ++i) {
        pos_err[i + 2] = _pos_des[i + 4] - pos_act[i];
        vel_des[i + 2] = _vel_des[i + 3];
        acc_des[i + 2] = _acc_des[i + 3];
    }

    // myUtils::pretty_print(des_ori, std::cout, "ori_des");
    // myUtils::pretty_print(ori_act, std::cout, "ori_act");
    // myUtils::pretty_print(pos_err, std::cout, "pos_err in bodyrpz");

    return true;
}

bool LineFootTask::_UpdateTaskJacobian() {
    Eigen::MatrixXd Jtmp = robot_->getBodyNodeJacobian(link_idx_);
    // (Ry, Rz)
    Jt_.block(0, 0, 2, robot_->getNumDofs()) =
        Jtmp.block(1, 0, 2, robot_->getNumDofs());
    // (x, y, z)
    Jt_.block(2, 0, 3, robot_->getNumDofs()) =
        Jtmp.block(3, 0, 3, robot_->getNumDofs());
    // isolate virtual joint
    Jt_.block(0, 0, dim_task_, robot_->getNumVirtualDofs()) =
        Eigen::MatrixXd::Zero(dim_task_, robot_->getNumVirtualDofs());

    return true;
}

bool LineFootTask::_UpdateTaskJDotQdot() {
    Eigen::VectorXd v_tmp =
        robot_->getBodyNodeJacobianDot(link_idx_) * robot_->getQdot();
    JtDotQdot_ = v_tmp.tail(dim_task_);

    // JtDotQdot_.setZero();
    return true;
}
