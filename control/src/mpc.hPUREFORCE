#ifndef MPC_H
#define MPC_H

#include <math.h>
#include <RocketSolver.h>
#include <RocketSolver_memory.h>
#include <RocketSolver_adtool2forces.h>

#include <Publisher_s.h>
#include <Subscriber_s.h>

// controls msg SITL
#include <actuator_controls_sitl/actuator_controlsPubSubTypes.h>
#include <actuator_controls_sitl/actuator_controls.h>

// controls msg 
#include <actuator_controls/actuator_controls_0PubSubTypes.h>
#include <actuator_controls/actuator_controls_0.h>

// mavlink cmds msg
#include<commands/vehicle_command.h>
#include<commands/vehicle_commandPubSubTypes.h>

// fsm msgs
#include<fsmDataOut/fsmDataOut.h>
#include<fsmDataOut/fsmDataOutPubSubTypes.h>

// xyz vxvyvz msg
#include<vehicle_local_position_groundtruth/vehicle_local_position_groundtruth.h>
#include<vehicle_local_position_groundtruth/vehicle_local_position_groundtruthPubSubTypes.h>

// wxwywz msg
#include<vehicle_angular_velocity_groundtruth/vehicle_angular_velocity_groundtruth.h>
#include<vehicle_angular_velocity_groundtruth/vehicle_angular_velocity_groundtruthPubSubTypes.h>

// quaternions msg
#include<vehicle_attitude_groundtruth/vehicle_attitude_groundtruth.h>
#include<vehicle_attitude_groundtruth/vehicle_attitude_groundtruthPubSubTypes.h>



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <chrono>





const int x0_sz = 160;
const int xinit_sz = 13;
const int all_parameters_sz = 80;
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
