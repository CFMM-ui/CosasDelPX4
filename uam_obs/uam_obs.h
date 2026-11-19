#pragma once

#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <uORB/SubscriptionInterval.hpp>
#include <uORB/topics/parameter_update.h>

using namespace time_literals;

extern "C" __EXPORT int uam_obs_main(int argc, char *argv[]);

class UAM_OBS : public ModuleBase<UAM_OBS>, public ModuleParams
{
public:
    UAM_OBS(int example_param, bool example_flag);

    virtual ~UAM_OBS() = default;

    static int task_spawn(int argc, char *argv[]);

    static UAM_OBS *instantiate(int argc, char *argv[]);

    static int print_usage(const char *reason = nullptr);

    static int custom_command(int argc, char *argv[]);

    void run() override;

    int print_status() override;

private:
void parameters_update(bool force = false);

    DEFINE_PARAMETERS(

    (ParamFloat<px4::params::X_E1>) _x_e1,
    (ParamFloat<px4::params::X_E2>) _x_e2,
    (ParamFloat<px4::params::X_E3>) _x_e3,
    (ParamFloat<px4::params::X_E4>) _x_e4,
    (ParamFloat<px4::params::X_MU1>) _x_mu1,
    (ParamFloat<px4::params::X_MU2>) _x_mu2,
    (ParamFloat<px4::params::X_MU3>) _x_mu3,
    (ParamFloat<px4::params::X_ALPHA>) _x_alpha,
    (ParamFloat<px4::params::X_BETA>) _x_beta,

    (ParamFloat<px4::params::Y_E1>) _y_e1,
    (ParamFloat<px4::params::Y_E2>) _y_e2,
    (ParamFloat<px4::params::Y_E3>) _y_e3,
    (ParamFloat<px4::params::Y_E4>) _y_e4,
    (ParamFloat<px4::params::Y_MU1>) _y_mu1,
    (ParamFloat<px4::params::Y_MU2>) _y_mu2,
    (ParamFloat<px4::params::Y_MU3>) _y_mu3,
    (ParamFloat<px4::params::Y_ALPHA>) _y_alpha,
    (ParamFloat<px4::params::Y_BETA>) _y_beta,

    (ParamFloat<px4::params::Z_E1>) _z_e1,
    (ParamFloat<px4::params::Z_E2>) _z_e2,
    (ParamFloat<px4::params::Z_E3>) _z_e3,
    (ParamFloat<px4::params::Z_E4>) _z_e4,
    (ParamFloat<px4::params::Z_MU1>) _z_mu1,
    (ParamFloat<px4::params::Z_MU2>) _z_mu2,
    (ParamFloat<px4::params::Z_MU3>) _z_mu3,
    (ParamFloat<px4::params::Z_ALPHA>) _z_alpha,
    (ParamFloat<px4::params::Z_BETA>) _z_beta,

    (ParamFloat<px4::params::ROLL_E1>) _roll_e1,
    (ParamFloat<px4::params::ROLL_E2>) _roll_e2,
    (ParamFloat<px4::params::ROLL_E3>) _roll_e3,
    (ParamFloat<px4::params::ROLL_E4>) _roll_e4,
    (ParamFloat<px4::params::ROLL_MU1>) _roll_mu1,
    (ParamFloat<px4::params::ROLL_MU2>) _roll_mu2,
    (ParamFloat<px4::params::ROLL_MU3>) _roll_mu3,
    (ParamFloat<px4::params::ROLL_ALPHA>) _roll_alpha,
    (ParamFloat<px4::params::ROLL_BETA>) _roll_beta,

    (ParamFloat<px4::params::PITCH_E1>) _pitch_e1,
    (ParamFloat<px4::params::PITCH_E2>) _pitch_e2,
    (ParamFloat<px4::params::PITCH_E3>) _pitch_e3,
    (ParamFloat<px4::params::PITCH_E4>) _pitch_e4,
    (ParamFloat<px4::params::PITCH_MU1>) _pitch_mu1,
    (ParamFloat<px4::params::PITCH_MU2>) _pitch_mu2,
    (ParamFloat<px4::params::PITCH_MU3>) _pitch_mu3,
    (ParamFloat<px4::params::PITCH_ALPHA>) _pitch_alpha,
    (ParamFloat<px4::params::PITCH_BETA>) _pitch_beta,

    (ParamFloat<px4::params::YAW_E1>) _yaw_e1,
    (ParamFloat<px4::params::YAW_E2>) _yaw_e2,
    (ParamFloat<px4::params::YAW_E3>) _yaw_e3,
    (ParamFloat<px4::params::YAW_E4>) _yaw_e4,
    (ParamFloat<px4::params::YAW_MU1>) _yaw_mu1,
    (ParamFloat<px4::params::YAW_MU2>) _yaw_mu2,
    (ParamFloat<px4::params::YAW_MU3>) _yaw_mu3,
    (ParamFloat<px4::params::YAW_ALPHA>) _yaw_alpha,
    (ParamFloat<px4::params::YAW_BETA>) _yaw_beta,

    (ParamFloat<px4::params::L_ONE_E1>) _one_e1,
    (ParamFloat<px4::params::L_ONE_E2>) _one_e2,
    (ParamFloat<px4::params::L_ONE_E3>) _one_e3,
    (ParamFloat<px4::params::L_ONE_E4>) _one_e4,
    (ParamFloat<px4::params::L_ONE_MU1>) _one_mu1,
    (ParamFloat<px4::params::L_ONE_MU2>) _one_mu2,
    (ParamFloat<px4::params::L_ONE_MU3>) _one_mu3,
    (ParamFloat<px4::params::L_ONE_ALPHA>) _one_alpha,
    (ParamFloat<px4::params::L_ONE_BETA>) _one_beta,
    
    (ParamFloat<px4::params::L_TWO_E1>) _two_e1,
    (ParamFloat<px4::params::L_TWO_E2>) _two_e2,
    (ParamFloat<px4::params::L_TWO_E3>) _two_e3,
    (ParamFloat<px4::params::L_TWO_E4>) _two_e4,
    (ParamFloat<px4::params::L_TWO_MU1>) _two_mu1,
    (ParamFloat<px4::params::L_TWO_MU2>) _two_mu2,
    (ParamFloat<px4::params::L_TWO_MU3>) _two_mu3,
    (ParamFloat<px4::params::L_TWO_ALPHA>) _two_alpha,
    (ParamFloat<px4::params::L_TWO_BETA>) _two_beta

    )

    uORB::SubscriptionInterval _parameter_update_sub{ORB_ID(parameter_update), 1_s};
};