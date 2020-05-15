
#ifndef H_IHWBC_JOINT_INTEGRATOR
#define H_IHWBC_JOINT_INTEGRATOR

#include <iostream>
#include <Utils/Math/MathUtilities.hpp>

class IHWBC_JointIntegrator{
public:
    IHWBC_JointIntegrator(const int num_joints_in, 
                          const double dt_in);

    IHWBC_JointIntegrator(const int num_joints_in, 
                          const double vel_cutoff_in,
                          const double pos_cutoff_in,
                          const double dt_in);

    // Function: performs a leaky integration on the velocity and position.
    // Inputs: the current joint acceleration, velocity and position.
    // Outputs: the integrated velocity and position values.
    void integrate(const Eigen::VectorXd acc_in, const Eigen::VectorXd & vel_in, const Eigen::VectorXd & pos_in, 
                   Eigen::VectorXd & vel_out, Eigen::VectorXd & pos_out);

    // Setters
    void setDt(const double dt_in);
    void setVelocityFrequencyCutOff(const double vel_cutoff_in);
    void setPositionFrequencyCutOff(const double pos_cutoff_in);
    void setVelocityBounds(const Eigen::VectorXd vel_min_in, const Eigen::VectorXd vel_max_in);
    void setPositionBounds(const Eigen::VectorXd pos_min_in, const Eigen::VectorXd pos_max_in);

    // Sets the maximum position deviation from current position for all joints
    void setMaxPositionError(const double pos_max_error_in);
    // Use custom maximum position deviation from current position for each joint
    void setMaxPositionErrorVector(const Eigen::VectorXd pos_max_error_in);

    // Debug
    void printIntegrationParams();

private:
    int n_joints_; //number of joints 
    double vel_freq_cutoff_; // frequency cut-off for the velocity  in Hz
    double pos_freq_cutoff_; // frequency cut-off for the position in Hz
    double alpha_vel_; // the equivalent alpha cut-off for velocity integration
    double alpha_pos_; // the equivalent alpha cut-off for position integration
    double dt_; // integration time in seconds

    // Internal Integration States
    Eigen::VectorXd vel_;
    Eigen::VectorXd pos_;

    // Velocity Bounds
    Eigen::VectorXd vel_min_;
    Eigen::VectorXd vel_max_;

    // Position Bounds
    Eigen::VectorXd pos_min_;
    Eigen::VectorXd pos_max_;
    Eigen::VectorXd pos_max_error_; // maximum error from current position

    // Defaults
    double default_vel_freq_cutoff_ = 2.0; // Hz
    double default_pos_freq_cutoff_ = 1.0; // Hz

    void setDefaultSaturation();
    double default_vel_min_max_ = 10; // +/- radians/s
    double default_pos_min_max_ = 2*M_PI; //  +/- radians
    double default_pos_max_error_ = 0.2; // radians maximum position deviation from actual

    // Helper Functions
    // Ouptuts alpha \in [0,1] from a set frequency and dt
    double getAlphaFromFrequency(const double hz, const double dt);
    // Clamps a value to be within min and max bounds
    double clampValue(double in, double min, double max);
    // Clamps a vector value to be within min and max bounds. 
    Eigen::VectorXd clampVec(Eigen::VectorXd vec_in, 
                             Eigen::VectorXd vec_min,
                             Eigen::VectorXd vec_max);

};

#endif 

