#pragma once

#include <map>
#include <string>

#include "PnC/Interface.hpp"

class AtlasStateProvider;
class AtlasStateEstimator;

class AtlasSensorData {
public:
  AtlasSensorData() {}
  virtual ~AtlasSensorData() {}

  Eigen::Vector3d base_com_pos;
  Eigen::Quaternion<double> base_com_quat;
  Eigen::Vector3d base_com_lin_vel;
  Eigen::Vector3d base_com_ang_vel;
  Eigen::Vector3d base_joint_pos;
  Eigen::Quaternion<double> base_joint_quat;
  Eigen::Vector3d base_joint_lin_vel;
  Eigen::Vector3d base_joint_ang_vel;
  std::map<std::string, double> joint_pos;
  std::map<std::string, double> joint_vel;

  bool b_rf_contact;
  bool b_lf_contact;
};

class AtlasCommand {
public:
  AtlasCommand() {}
  virtual ~AtlasCommand() {}

  std::map<std::string, double> joint_pos;
  std::map<std::string, double> joint_vel;
  std::map<std::string, double> joint_trq;
};

class AtlasInterface : public Interface {
protected:
  AtlasStateEstimator *se_;
  AtlasStateProvider *sp_;

  int waiting_count_;

public:
  AtlasInterface();
  virtual ~AtlasInterface();
  virtual void getCommand(void *_sensor_data, void *_command_data);
};
