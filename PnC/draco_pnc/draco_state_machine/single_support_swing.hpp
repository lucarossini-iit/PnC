#pragma once

#include "PnC/StateMachine.hpp"
#include "PnC/draco_pnc/draco_control_architecture.hpp"
#include "PnC/draco_pnc/draco_controller.hpp"
#include "PnC/draco_pnc/draco_state_provider.hpp"

class SingleSupportSwing : public StateMachine {
public:
  SingleSupportSwing(const StateIdentifier state_identifier_in,
                     DracoControlArchitecture *_ctrl_arch, int _leg_side,
                     RobotSystem *_robot);
  ~SingleSupportSwing();

  void oneStep();
  void firstVisit();
  void lastVisit();
  bool endOfState();
  StateIdentifier getNextState();

protected:
  DracoStateProvider *sp_;
  DracoControlArchitecture *ctrl_arch_;

  double ctrl_start_time_;
  int leg_side_;

  double end_time_;
};
