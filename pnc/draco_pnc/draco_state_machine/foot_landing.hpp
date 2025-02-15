#pragma once

#include "pnc/state_machine.hpp"
#include "pnc/draco_pnc/draco_control_architecture.hpp"
#include "pnc/draco_pnc/draco_controller.hpp"
#include "pnc/draco_pnc/draco_state_provider.hpp"

class FootLanding : public StateMachine {
public:
  FootLanding(const StateIdentifier state_identifier_in,
                         DracoControlArchitecture *_ctrl_arch, int _leg_side,
                         RobotSystem *_robot);
  ~FootLanding();

  void oneStep();
  void firstVisit();
  void lastVisit();
  bool endOfState();
  StateIdentifier getNextState();
  double ramp_time_;

  bool b_static_walking_trigger;

protected:
  DracoStateProvider *sp_;
  DracoControlArchitecture *ctrl_arch_;

  double ctrl_start_time_;
  int leg_side_;
};
