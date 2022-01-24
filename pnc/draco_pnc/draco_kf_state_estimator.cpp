#include "draco_kf_state_estimator.hpp"

DracoKFStateEstimator::DracoKFStateEstimator(RobotSystem *_robot) :
HumanoidStateEstimator(_robot) {
  util::PrettyConstructor(1, "DracoKFStateEstimator");
  sp_ = DracoStateProvider::getStateProvider();

  YAML::Node cfg = YAML::LoadFile(THIS_COM "config/draco/pnc.yaml");
   margFilter_ = new MARGFilter();

  rot_world_to_base.setZero();
  iso_base_com_to_imu_ = robot_->get_link_iso("torso_link").inverse() *
                         robot_->get_link_iso("torso_imu");
  iso_base_joint_to_imu_.linear() = iso_base_com_to_imu_.linear();
  iso_base_joint_to_imu_.translation() =
          iso_base_com_to_imu_.translation() +
          robot_->get_link_iso("torso_link").linear() *
          robot_->get_base_local_com_pos();

  global_linear_offset_.setZero();
  prev_base_joint_pos_.setZero();
  prev_base_com_pos_.setZero();

  Eigen::VectorXd n_data_com_vel = util::ReadParameter<Eigen::VectorXd>(
          cfg["state_estimator"], "n_data_com_vel");
  Eigen::VectorXd n_data_ang_vel = util::ReadParameter<Eigen::VectorXd>(
          cfg["state_estimator"], "n_data_ang_vel");
  Eigen::VectorXd n_data_cam = util::ReadParameter<Eigen::VectorXd>(
          cfg["state_estimator"], "n_data_cam");

  for (int i = 0; i < 3; ++i) {
      com_vel_filter_.push_back(SimpleMovingAverage(n_data_com_vel[i]));
      imu_ang_vel_filter_.push_back(SimpleMovingAverage(n_data_ang_vel[i]));
      cam_filter_.push_back(SimpleMovingAverage(n_data_cam[i]));
  }

  b_first_visit_ = true;
}

DracoKFStateEstimator::~DracoKFStateEstimator() {
  delete margFilter_;
}

void DracoKFStateEstimator::initialize(HumanoidSensorData *data) {
    this->update(data);
}

void DracoKFStateEstimator::update(HumanoidSensorData *data) {

  // estimate 0_R_b
//  margFilter_->filterUpdate(data->imu_frame_vel[0], data->imu_frame_vel[1], data->imu_frame_vel[2],
//                            data->imu_accel[0], data->imu_accel[1], data->imu_accel[2],
//                            data->imu_magnet[0], data->imu_magnet[1], data->imu_magnet[2]);
//  rot_world_to_base = margFilter_->getBaseRotation();

  // Kalman process model

  // Kalman measurement model

  if (data->b_rf_contact) {
      sp_->b_rf_contact = true;
  } else {
      sp_->b_rf_contact = false;
  }

  if (data->b_lf_contact) {
      sp_->b_lf_contact = true;
  } else {
      sp_->b_lf_contact = false;
  }

//    this->_update_dcm();
}
