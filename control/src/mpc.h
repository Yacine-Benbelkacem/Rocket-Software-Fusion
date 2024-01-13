#ifndef MPC_H
#define MPC_H



#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <chrono>

#define test_pid 0
#define simulation 1
#define verbose 1
#define pure_force 1
//#define acado  // POSSIBLE VALUES : ACADO , FORCES

// Solver

#ifdef FORCES

#include <RocketSolver.h>
#include <RocketSolver_memory.h>
#include <RocketSolver_adtool2forces.h>

#else //ACADO

#include "acado_common.h"
#include "acado_auxiliary_functions.h"

/* Some convenient definitions. */
#define NX          ACADO_NX  /* Number of differential state variables.  */
#define NXA         ACADO_NXA /* Number of algebraic variables. */
#define NU          ACADO_NU  /* Number of control inputs. */
#define NOD         ACADO_NOD  /* Number of online data values. */

#define NY          ACADO_NY  /* Number of measurements/references on nodes 0..N - 1. */
#define NYN         ACADO_NYN /* Number of measurements/references on node N. */

#define Nsteps           10   /* Number of intervals in the horizon. */

#define NUM_STEPS   10        /* Number of real-time iterations. */
#define VERBOSE     0        /* Show iterations: 1, silent: 0.  */


#endif





//Middleware
#include <publisher/publisher_s.h>
#include <subscriber/subscriber_s.h>

#if simulation
// xyz vxvyvz msg
#include<messages/vehicle_local_position_groundtruth/vehicle_local_position_groundtruthPubSubTypes.h>

// wxwywz msg
#include<messages/vehicle_angular_velocity_groundtruth/vehicle_angular_velocity_groundtruthPubSubTypes.h>

// quaternions msg
#include<messages/vehicle_attitude_groundtruth/vehicle_attitude_groundtruthPubSubTypes.h>

#else

#include<messages/vehicle_odometry/vehicle_odometryPubSubTypes.h>

#endif

// controls msg
#include <messages/actuator_controls/actuator_controlsPubSubTypes.h>
// controls msg 
#include <messages/actuator_controls_0/actuator_controls_0PubSubTypes.h>
// mavlink cmds msg
#include<messages/vehicle_command/vehicle_commandPubSubTypes.h>
// fsm msgs
#include<messages/fsmDataOut/fsmDataOutPubSubTypes.h>


// Solver characteristics

#ifdef FORCES
    const int x0_sz = 480;
    const int xinit_sz = 13;
    const int all_parameters_sz = 240;
    const int all_parameters_nb = 8;

    void fill_x0(RocketSolver_params * p , int size);
    void fill_xinit(RocketSolver_params * p , int size);
    void fill_params(RocketSolver_params * p , int size, int nparam);
    void set_altitude(RocketSolver_params * p , int size, int nparam, double altitude);
#else
    void fill_xinit_acado();
#endif

uint64_t timeSinceEpochMicrosec();
inline double deg2rad(double degrees);

double deg2rad(double degrees);

double magnitude_thrust(double thrustx, double thrusty, double thrustz);

void Thrust2cmds(double thrustx, double thrusty, double thrustz, actuator_controls_0__float_array_8* cmd);

void quaternionToEuler(double w, double x, double y, double z, double &roll, double &pitch, double &yaw);


void mpc_init();

void mpc_hover();
void mpc_land();
void mpc_stop();

void mpc_iterate();


#endif

