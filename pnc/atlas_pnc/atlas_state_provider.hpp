#pragma once

#include <map>
#include <string>

#include <configuration.hpp>
#include <utils/util.hpp>

class RobotSystem;

class AtlasStateProvider {
public:
  static AtlasStateProvider *getStateProvider(RobotSystem *_robot);
  ~AtlasStateProvider() {}

  std::map<std::string, double> nominal_joint_pos;

  int state;
  int prev_state;

  double curr_time;
  double servo_dt = 0.001;

  Eigen::Vector3d dcm;
  Eigen::Vector3d prev_dcm;
  Eigen::Vector3d dcm_vel;

  int b_rf_contact;
  int b_lf_contact;

  int planning_id = 0;

private:
  AtlasStateProvider(RobotSystem *_robot);
  RobotSystem *robot_;
};
