#include "pnc/draco_pnc/draco_interface.hpp"

#include <math.h>
#include <stdio.h>
#include <string>

#include "pnc/draco_pnc/draco_control_architecture.hpp"
#include "pnc/draco_pnc/draco_interrupt_logic.hpp"
#include "pnc/draco_pnc/draco_state_estimator.hpp"
#include "pnc/draco_pnc/draco_state_provider.hpp"
#include "pnc/robot_system/dart_robot_system.hpp"
#include "utils/util.hpp"

DracoInterface::DracoInterface(bool _b_sim) : Interface() {
  std::string border = "=";
  for (int i = 0; i < 79; ++i) {
    border += "=";
  }
  util::ColorPrint(color::kBoldCyan, border);
  util::PrettyConstructor(0, "Draco Interface");

  YAML::Node cfg = YAML::LoadFile(THIS_COM "config/draco/pnc.yaml");

  robot_ = new DartRobotSystem(THIS_COM "robot_model/draco/draco_rel_path.urdf",
                               false, false);
  se_ = new DracoStateEstimator(robot_);
  sp_ = DracoStateProvider::getStateProvider();
  sp_->servo_dt = util::ReadParameter<double>(cfg, "servo_dt");
  sp_->save_freq = util::ReadParameter<int>(cfg, "save_freq");

  count_ = 0;
  waiting_count_ = 10;
  smoothing_count_ = 20;

  control_architecture_ = new DracoControlArchitecture(robot_);
  if (_b_sim) {
    control_architecture_->state = draco_states::kStand;
    sp_->state = control_architecture_->state;
  } else {
    control_architecture_->state = draco_states::kInitialize;
    sp_->state = control_architecture_->state;
  }
  interrupt = new DracoInterruptLogic(
      static_cast<DracoControlArchitecture *>(control_architecture_));

  DracoDataManager::GetDracoDataManager()->InitializeSockets(
      util::ReadParameter<std::string>(cfg, "ip_addr"));

  util::ColorPrint(color::kBoldCyan, border);
}

DracoInterface::~DracoInterface() {
  delete robot_;
  delete se_;
  delete interrupt;
  delete control_architecture_;
}

void DracoInterface::getCommand(void *_data, void *_command) {
  DracoCommand *cmd = ((DracoCommand *)_command);
  DracoSensorData *data = ((DracoSensorData *)_data);

  if (count_ <= waiting_count_) {
    se_->initialize(data);
    this->SetSafeCommand(data, cmd);
  } else {
    se_->update(data);
    interrupt->processInterrupts();
    control_architecture_->getCommand(cmd);
    if (count_ <= waiting_count_ + smoothing_count_) {
      this->SmoothCommand(cmd);
    }
  }

  if (sp_->count != 0 && sp_->count % sp_->save_freq == 0) {
    DracoDataManager::GetDracoDataManager()->data->time = sp_->curr_time;
    DracoDataManager::GetDracoDataManager()->data->phase = sp_->state;
    DracoDataManager::GetDracoDataManager()->Send();
  }

  ++count_;
  running_time_ = (double)(count_)*sp_->servo_dt;
  sp_->count = count_;
  sp_->curr_time = running_time_;
  sp_->prev_state = control_architecture_->prev_state;
  sp_->state = control_architecture_->state;
}

void DracoInterface::SmoothCommand(DracoCommand *cmd) {
  double s = static_cast<double>(count_ - waiting_count_) /
             static_cast<double>(smoothing_count_);
  for (std::map<std::string, double>::iterator it =
           cmd->joint_velocities.begin();
       it != cmd->joint_velocities.end(); ++it) {
    cmd->joint_velocities[it->first] *= s;
    cmd->joint_torques[it->first] *= s;
  }
}

void DracoInterface::SetSafeCommand(DracoSensorData *data, DracoCommand *cmd) {
  for (std::map<std::string, double>::iterator it =
           data->joint_positions.begin();
       it != data->joint_positions.end(); it++) {
    cmd->joint_positions[it->first] = data->joint_positions[it->first];
    cmd->joint_velocities[it->first] = 0.;
    cmd->joint_torques[it->first] = 0.;
  }
}
