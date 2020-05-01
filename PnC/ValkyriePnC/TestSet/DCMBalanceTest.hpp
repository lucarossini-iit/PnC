#pragma once

#include <PnC/Test.hpp>

class ValkyrieStateProvider;

namespace DCM_BLPhase {
constexpr int BALANCE = 0;
constexpr int SWING = 1;
};  // namespace BLPhase

class DCMBalanceTest : public Test {
   public:
    DCMBalanceTest(RobotSystem*);
    virtual ~DCMBalanceTest();
    virtual void TestInitialization();

   protected:
    int num_step_;
    ValkyrieStateProvider* sp_;
    virtual int _NextPhase(const int& phase);
    virtual void AdditionalUpdate_();
    void _SettingParameter();

    Controller* balance_ctrl_;
    Controller* swing_ctrl_;

    YAML::Node cfg_;
};
