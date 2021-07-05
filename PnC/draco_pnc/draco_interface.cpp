#include "PnC/draco_pnc/draco_interface.hpp"

#include <math.h>
#include <stdio.h>
#include <string>

#include "PnC/RobotSystem/DartRobotSystem.hpp"
#include "PnC/draco_pnc/draco_control_architecture.hpp"
#include "PnC/draco_pnc/draco_interrupt_logic.hpp"
#include "PnC/draco_pnc/draco_state_estimator.hpp"
#include "PnC/draco_pnc/draco_state_provider.hpp"
#include "utils/util.hpp"

DracoInterface::DracoInterface(bool _b_sim) : Interface() {
  std::string border = "=";
  for (int i = 0; i < 79; ++i) {
    border += "=";
  }
  util::ColorPrint(color::kBoldCyan, border);
  util::PrettyConstructor(0, "Draco Interface");

  YAML::Node cfg = YAML::LoadFile(THIS_COM "Config/draco/pnc.yaml");

  robot_ = new DartRobotSystem(THIS_COM "RobotModel/draco/draco_rel_path.urdf",
                               false, false);
  se_ = new DracoStateEstimator(robot_);
  sp_ = DracoStateProvider::getStateProvider();
  sp_->servo_rate = util::ReadParameter<double>(cfg, "servo_rate");

  count_ = 0;
  waiting_count_ = 2;

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

  if (count_ == 0) {
    se_->initialize(data);
    // DataManager::GetDataManager()->start();
  }
  se_->update(data);
  interrupt->processInterrupts();
  control_architecture_->getCommand(cmd);

  ++count_;
  running_time_ = (double)(count_)*sp_->servo_rate;
  sp_->curr_time = running_time_;
  sp_->prev_state = control_architecture_->prev_state;
  sp_->state = control_architecture_->state;
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
