#pragma once

#include "pnc/draco_pnc/draco_interface.hpp"
#include "pnc/draco_pnc/draco_state_provider.hpp"
#include "pnc/draco_pnc/draco_tci_container.hpp"
#include "pnc/robot_system/robot_system.hpp"
#include "pnc/whole_body_controllers/ihwbc/ihwbc.hpp"
#include "pnc/whole_body_controllers/ihwbc/joint_integrator.hpp"

class DracoController {
public:
  DracoController(DracoTCIContainer *_tci_container, RobotSystem *_robot);
  virtual ~DracoController();

  void getCommand(void *_cmd);

  void SaveData();

private:
  /* data */
  RobotSystem *robot_;
  IHWBC *wbc_;
  JointIntegrator *joint_integrator_;

  DracoTCIContainer *tci_container_;
  DracoStateProvider *sp_;

  Eigen::VectorXd joint_trq_cmd_;
  Eigen::VectorXd joint_acc_cmd_;
  Eigen::VectorXd cmd_lfoot_rf_;
  Eigen::VectorXd cmd_rfoot_rf_;
  Eigen::VectorXd joint_pos_cmd_;
  Eigen::VectorXd joint_vel_cmd_;

  double l_knee_int_frc_cmd_;
  double r_knee_int_frc_cmd_;

  Eigen::MatrixXd sa_;
  Eigen::MatrixXd sv_;
  Eigen::MatrixXd sf_;

  bool b_smoothing_cmd_;
  double smoothing_duration_;
  double smoothing_start_time_;
  Eigen::VectorXd smoothing_start_joint_positions_;

  void FirstVisit();

  // Smooth increment of the commands
  void SmoothCommand();

  bool b_first_visit_;

  YAML::Node cfg_;
};
