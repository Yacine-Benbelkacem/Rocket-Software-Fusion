#ifndef MPC_H
#define MPC_H
#define __isoc99_fscanf fscanf

#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "./RocketSolver/include/RocketSolver.h"
#include "./RocketSolver/include/RocketSolver_memory.h"
#include "./RocketSolver/include/RocketSolver_adtool2forces.h"


#include <unistd.h>
#include <pthread.h>










void fill_x0(RocketSolver_params * p , int size);
void fill_xinit(RocketSolver_params * p , int size);
void fill_params(RocketSolver_params * p , int size, int nparam);
void set_altitude(RocketSolver_params * p , int size, int nparam, double altitude);


//uint64_t timeSinceEpochMicrosec();
//inline double deg2rad(double degrees);

void mpc_init();
void mpc_hover();
void mpc_ascend();
void mpc_land();
void mpc_run();

//double deg2rad(double degrees);

double magnitude_thrust(RocketSolver_output thrust);

//void Thrust2cmds(RocketSolver_output thrust , actuator_controls_0__float_array_8* cmd);

//void quaternionToEuler(double w, double x, double y, double z, double &roll, double &pitch, double &yaw);

#endif
