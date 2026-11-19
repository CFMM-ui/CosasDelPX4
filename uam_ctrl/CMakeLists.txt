px4_add_module(
	MODULE modules__uam_ctrl
	MAIN uam_ctrl
	SRCS
	    uam_ctrl.cpp
	MODULE_CONFIG
	    module.yaml
	)