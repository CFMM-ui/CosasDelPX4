#pragma once

#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <uORB/SubscriptionInterval.hpp>
#include <uORB/topics/parameter_update.h>

using namespace time_literals;

extern "C" __EXPORT int uam_ctrl_main(int argc, char *argv[]);

class UAM_CTRL : public ModuleBase<UAM_CTRL>, public ModuleParams
{
public:
    UAM_CTRL(int example_param, bool example_flag);

    virtual ~UAM_CTRL() = default;

    static int task_spawn(int argc, char *argv[]);

    static UAM_CTRL *instantiate(int argc, char *argv[]);

    static int print_usage(const char *reason = nullptr);

    static int custom_command(int argc, char *argv[]);

    void run() override;

    int print_status() override;

private:
void parameters_update(bool force = false);

    DEFINE_PARAMETERS(
        (ParamFloat<px4::params::UAM_X_P>) _uam_x_p,
        (ParamFloat<px4::params::UAM_X_D>) _uam_x_d,
        (ParamFloat<px4::params::UAM_Y_P>) _uam_y_p,
        (ParamFloat<px4::params::UAM_Y_D>) _uam_y_d,
        (ParamFloat<px4::params::UAM_Z_P>) _uam_z_p,
        (ParamFloat<px4::params::UAM_Z_D>) _uam_z_d,
        
        (ParamFloat<px4::params::UAM_ROLL_P>) _uam_roll_p,
        (ParamFloat<px4::params::UAM_ROLL_D>) _uam_roll_d,
        (ParamFloat<px4::params::UAM_PITCH_P>) _uam_pitch_p,
        (ParamFloat<px4::params::UAM_PITCH_D>) _uam_pitch_d,
        (ParamFloat<px4::params::UAM_YAW_P>) _uam_yaw_p,
        (ParamFloat<px4::params::UAM_YAW_D>) _uam_yaw_d,
        
        (ParamFloat<px4::params::UAM_L_ONE_P>) _uam_link_one_p,
        (ParamFloat<px4::params::UAM_L_ONE_D>) _uam_link_one_d,
        (ParamFloat<px4::params::UAM_L_TWO_P>) _uam_link_two_p,
        (ParamFloat<px4::params::UAM_L_TWO_D>) _uam_link_two_d,

        (ParamFloat<px4::params::UAM_MASS>) _uam_mass,
        (ParamFloat<px4::params::UAM_I_XX>) _uam_i_xx,
        (ParamFloat<px4::params::UAM_I_YY>) _uam_i_yy,
        (ParamFloat<px4::params::UAM_I_ZZ>) _uam_i_zz,

        (ParamFloat<px4::params::UAM_L_ONE_MASS>) _uam_link_one_mass,
        (ParamFloat<px4::params::UAM_L_ONE_I_XX>) _uam_link_one_xx,
        (ParamFloat<px4::params::UAM_L_ONE_I_YY>) _uam_link_one_yy,
        (ParamFloat<px4::params::UAM_L_ONE_I_ZZ>) _uam_link_one_zz,

        (ParamFloat<px4::params::UAM_L_TWO_MASS>) _uam_link_two_mass,
        (ParamFloat<px4::params::UAM_L_TWO_I_XX>) _uam_link_two_xx,
        (ParamFloat<px4::params::UAM_L_TWO_I_YY>) _uam_link_two_yy,
        (ParamFloat<px4::params::UAM_L_TWO_I_ZZ>) _uam_link_two_zz,

        (ParamInt<px4::params::TRAJ_SEL>) _traj_sel
    )

    uORB::SubscriptionInterval _parameter_update_sub{ORB_ID(parameter_update), 1_s};
};