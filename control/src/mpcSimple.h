#ifndef MPC_H
#define MPC_H


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include <RocketSolver.h>
#include <RocketSolver_memory.h>
#include <RocketSolver_adtool2forces.h>


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <chrono>





const int x0_sz = 480;
const int xinit_sz = 13;
const int all_parameters_sz = 240;
const int all_parameters_nb = 8;





void fill_x0(RocketSolver_params * p , int size);
void fill_xinit(RocketSolver_params * p , int size);
void fill_params(RocketSolver_params * p , int size, int nparam);
void set_altitude(RocketSolver_params * p , int size, int nparam, double altitude);


uint64_t timeSinceEpochMicrosec();
inline double deg2rad(double degrees);

void mpc_init();
void mpc_hover();
void mpc_ascend();
void mpc_land();
void mpc_run();

double deg2rad(double degrees);

double magnitude_thrust(RocketSolver_output thrust);

void Thrust2cmds(RocketSolver_output thrust , actuator_controls_0__float_array_8* cmd);

void quaternionToEuler(double w, double x, double y, double z, double &roll, double &pitch, double &yaw);

#endif
