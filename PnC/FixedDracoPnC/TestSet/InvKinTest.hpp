#pragma once

#include "PnC/Test.hpp"
#include "Utils/BSplineBasic.h"
#include "PnC/FixedDracoPnC/FixedDracoInterface.hpp"

class InvKinTest: public Test
{
public:
    InvKinTest (RobotSystem* robot_);
    virtual ~InvKinTest ();

    virtual void getTorqueInput(void* commandData_);
    virtual void initialize();

private:
    double mTestInitTime;
    Eigen::VectorXd mTestInitQ;
    BS_Basic<10, 3, 0, 2, 2> mSpline;
    Eigen::VectorXd mInterpolationGoal;
    double mInterpolationDuration;
};
