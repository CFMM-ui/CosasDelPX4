px4_add_module(
	MODULE modules__uam_obs
	MAIN uam_obs
	SRCS
	    uam_obs.cpp
	MODULE_CONFIG
	    module.yaml
	)