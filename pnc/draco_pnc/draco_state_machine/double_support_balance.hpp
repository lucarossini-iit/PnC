#pragma once

#include "pnc/draco_pnc/draco_control_architecture.hpp"
#include "pnc/draco_pnc/draco_controller.hpp"
#include "pnc/draco_pnc/draco_state_provider.hpp"
#include "pnc/state_machine.hpp"

class DoubleSupportBalance : public StateMachine {
public:
  DoubleSupportBalance(const StateIdentifier state_identifier_in,
                       DracoControlArchitecture *_ctrl_arch,
                       RobotSystem *_robot);
  ~DoubleSupportBalance();

  void oneStep();
  void firstVisit();
  void lastVisit();
  bool endOfState();
  StateIdentifier getNextState();

  bool b_walking_trigger;
  bool b_swaying_trigger;
  bool b_interpolation_trigger;
  bool b_static_walking_trigger;

protected:
  DracoStateProvider *sp_;
  DracoControlArchitecture *ctrl_arch_;

  double ctrl_start_time_;
};
