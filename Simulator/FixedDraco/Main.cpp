#include <dart/dart.hpp>
#include <dart/gui/osg/osg.hpp>
#include <dart/utils/utils.hpp>
#include <dart/utils/urdf/urdf.hpp>
#include "FixedDracoWorldNode.hpp"
#include "Configuration.h"
#include "Utils/ParamHandler.hpp"

void displayJointFrames(
    const dart::simulation::WorldPtr& world, 
    const dart::dynamics::SkeletonPtr& robot)
{
  for(std::size_t i=0; i < robot->getNumBodyNodes(); ++i)
  {
      dart::dynamics::BodyNode* bn = robot->getBodyNode(i);
      for(std::size_t j=0; j < bn->getNumChildJoints(); ++j)
      {
          const dart::dynamics::Joint* joint = bn->getChildJoint(j);
          const Eigen::Isometry3d offset = joint->getTransformFromParentBodyNode();

          dart::gui::osg::InteractiveFramePtr frame = std::make_shared<dart::gui::osg::InteractiveFrame>
              (bn,joint->getName()+"/frame", offset);

          for(const auto type : {dart::gui::osg::InteractiveTool::ANGULAR, dart::gui::osg::InteractiveTool::PLANAR})
              for(std::size_t i=0; i < 3; ++i)
                      frame->getTool(type, i)->setEnabled(false);

          world->addSimpleFrame(frame);
      }
  }
}

class OneStepProgress : public osgGA::GUIEventHandler
{
public:
    OneStepProgress(FixedDracoWorldNode* worldnode): worldnode_(worldnode){  }

    /** Deprecated, Handle events, return true if handled, false otherwise. */
    virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& /*aa*/)
    {
        if (ea.getEventType() == osgGA::GUIEventAdapter::KEYUP) {
            if (ea.getKey() == 'f') {
                int numStepProgress(10);
                for (int i = 0; i < numStepProgress; ++i) {
                    worldnode_->customPreStep();
                    worldnode_->getWorld()->step();
                    worldnode_->customPostStep();
                }
                return true;
            }
        }
        return false;
    }
    FixedDracoWorldNode* worldnode_;
};

void _printRobotModel(dart::dynamics::SkeletonPtr robot) {

    for (int i = 0; i < robot->getNumBodyNodes(); ++i) {
        dart::dynamics::BodyNodePtr bn = robot->getBodyNode(i);
        std::cout << i << "th" << std::endl;
        std::cout << bn->getName() << std::endl;
        std::cout << bn->getMass() << std::endl;
    }

    for (int i = 0; i < robot->getNumJoints(); ++i) {
        dart::dynamics::Joint* joint = robot->getJoint(i);
        std::cout << i << "th" << std::endl;
        std::cout << joint->getNumDofs() << std::endl;
    }

    //for (int i = 0; i < robot->getNumDofs(); ++i) {
        //dart::dynamics::DegreeOfFreedom* dof = robot->getDof(i);
        //std::cout << i << "th" << std::endl;
        //std::cout << dof->getName() << std::endl;
        //std::cout << "child body node name : " << dof->getChildBodyNode()->getName() << std::endl;
        //std::cout << dof->getCoulombFriction() << std::endl;
    //}

    //std::cout << robot->getNumDofs() << std::endl;
    //std::cout << robot->getNumJoints() << std::endl;
    //std::cout << robot->getMassMatrix().rows() << std::endl;
    //std::cout << robot->getMassMatrix().cols() << std::endl;

    exit(0);
}

void _setInitialConfiguration(dart::dynamics::SkeletonPtr robot) {

    int lKneeIdx = robot->getDof("lKnee")->getIndexInSkeleton();
    int lHipPitchIdx = robot->getDof("lHipPitch")->getIndexInSkeleton();
    int rKneeIdx = robot->getDof("rKnee")->getIndexInSkeleton();
    int rHipPitchIdx = robot->getDof("rHipPitch")->getIndexInSkeleton();
    int lAnkleIdx = robot->getDof("lAnkle")->getIndexInSkeleton();
    int rAnkleIdx = robot->getDof("rAnkle")->getIndexInSkeleton();

    int initPos(1); // 0 : Home, 1 : Bent
    Eigen::VectorXd q = robot->getPositions();

    switch (initPos) {
        case 0:
            q[5] = 1.425;
            //q[2] = 1.425;
            q[lAnkleIdx] = M_PI/2;
            q[rAnkleIdx] = M_PI/2;
            break;
        case 1:
            //q[5] = 1.34;
            //q[2] = 1.335;
            q[lHipPitchIdx] = -M_PI/8;
            q[lKneeIdx] = M_PI/4;
            q[rHipPitchIdx] = -M_PI/8;
            q[rKneeIdx] = M_PI/4;
            q[lAnkleIdx] = M_PI/2 - M_PI/8;
            q[rAnkleIdx] = M_PI/2 - M_PI/8;
            break;
        default:
            std::cout << "wrong initial pos case" << std::endl;
    }

    robot->setPositions(q);
}

int main() {
    // ========================
    // Parse Yaml for Simulator
    // ========================
    ParamHandler handler(THIS_COM"Config/FixedDraco/SIMULATION.yaml");
    bool isRecord;
    handler.getBoolean("IsRecord", isRecord);

    // ================================
    // Generate world and add skeletons
    // ================================
    dart::simulation::WorldPtr world(new dart::simulation::World);
    dart::utils::DartLoader urdfLoader;
    dart::dynamics::SkeletonPtr ground = urdfLoader.parseSkeleton(
            THIS_COM"RobotSystem/RobotModel/Ground/ground_terrain.urdf");
    dart::dynamics::SkeletonPtr robot = urdfLoader.parseSkeleton(
            THIS_COM"RobotSystem/RobotModel/Robot/Draco/DracoFixed.urdf");
    world->addSkeleton(ground);
    world->addSkeleton(robot);
    Eigen::Vector3d gravity(0.0, 0.0, -9.81);
    world->setGravity(gravity);
    world->setTimeStep(1.0/1500);

    // ====================
    // Display Joints Frame
    // ====================
    //displayJointFrames(world, robot);

    // =====================
    // Initial configuration
    // =====================
    _setInitialConfiguration(robot);

    ////////////
    // Collision
    ////////////

    //auto cd = world->getConstraintSolver()->getCollisionDetector();
    //std::cout << cd->getType() << std::endl;
    //std::cout << static_cast<dart::collision::FCLCollisionDetector*>(cd.get())->getPrimitiveShapeType() << std::endl;
    //std::cout << static_cast<dart::collision::FCLCollisionDetector*>(cd.get())->getContactPointComputationMethod() << std::endl;
    //static_cast<dart::collision::FCLCollisionDetector*>(cd.get())->setPrimitiveShapeType(dart::collision::FCLCollisionDetector::PRIMITIVE);
    //std::cout << static_cast<dart::collision::FCLCollisionDetector*>(cd.get())->getPrimitiveShapeType() << std::endl;
    //exit(0);

    // ================
    // Print Model Info
    // ================
    //_printRobotModel(robot);

    osg::ref_ptr<osgShadow::MinimalShadowMap> msm =
        new osgShadow::LightSpacePerspectiveShadowMapDB;

    float minLightMargin = 10.f;
    float maxFarPlane = 0;
    unsigned int texSize = 1024;
    unsigned int baseTexUnit = 0;
    unsigned int shadowTexUnit = 1;

    msm->setMinLightMargin( minLightMargin );
    msm->setMaxFarPlane( maxFarPlane );
    msm->setTextureSize( ::osg::Vec2s( texSize, texSize ) );
    msm->setShadowTextureCoordIndex( shadowTexUnit );
    msm->setShadowTextureUnit( shadowTexUnit );
    msm->setBaseTextureCoordIndex( baseTexUnit );
    msm->setBaseTextureUnit( baseTexUnit );

    // ================
    // Wrap a worldnode
    // ================
    osg::ref_ptr<FixedDracoWorldNode> node
        = new FixedDracoWorldNode(world, msm);
    node->setNumStepsPerCycle(30);

    // =====================
    // Create and Set Viewer
    // =====================

    dart::gui::osg::Viewer viewer;
    viewer.addWorldNode(node);
    viewer.simulate(false);
    viewer.switchHeadlights(false);
    msm->setLight(viewer.getLightSource(0)->getLight());
    ::osg::Vec3 p1(1.0, 0.2, 1.5);
    p1 = p1*0.7;
    viewer.getLightSource(0)->getLight()->setPosition(::osg::Vec4(p1[0], p1[1], p1[2], 0.0));
    viewer.getCamera()->setClearColor(osg::Vec4(0.93f, 0.95f, 1.0f, 0.95f));
    viewer.getCamera()->setClearMask(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    viewer.addEventHandler(new OneStepProgress(node) );

    if (isRecord) {
        std::cout << "[Video Record Enable]" << std::endl;
        viewer.record(THIS_COM"/ExperimentVideo");
    }

    //viewer.setUpViewInWindow(0, 0, 2880, 1800);
    viewer.setUpViewInWindow(1440, 0, 500, 500);
    viewer.getCameraManipulator()->setHomePosition(
            ::osg::Vec3( 5.14,  2.28, 3.0)*0.8,
            ::osg::Vec3( 0.0,  0.2, 0.5),
            ::osg::Vec3(0.0, 0.0, 1.0));
    viewer.setCameraManipulator(viewer.getCameraManipulator());
    viewer.run();
}
