#pragma once

#include "pnc/draco_pnc/draco_control_architecture.hpp"
#include "pnc/draco_pnc/draco_controller.hpp"
#include "pnc/draco_pnc/draco_state_provider.hpp"
#include "pnc/state_machine.hpp"

class FootLifting : public StateMachine {
public:
  FootLifting(const StateIdentifier state_identifier_in,
              DracoControlArchitecture *_ctrl_arch, int _leg_side,
              RobotSystem *_robot);
  ~FootLifting();

  void oneStep();
  void firstVisit();
  void lastVisit();
  bool endOfState();
  StateIdentifier getNextState();
  double ramp_time_;

  bool b_step_by_step = true;

protected:
  DracoStateProvider *sp_;
  DracoControlArchitecture *ctrl_arch_;

  double ctrl_start_time_;
  int leg_side_;
};
