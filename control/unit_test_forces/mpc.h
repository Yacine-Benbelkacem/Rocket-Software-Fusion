#ifndef MPC_H
#define MPC_H

#include <math.h>
#include <RocketSolver.h>
#include <RocketSolver_memory.h>
#include <RocketSolver_adtool2forces.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC

#define ROWS 100 // Maximum number of rows in the CSV file
#define COLS 13 // Number of columns in the CSV file
// Solver characteristics


double matrix[ROWS][COLS]; // Define a two-dimensional array to store the values


const int x0_sz = 160;
const int xinit_sz = 13;
const int all_parameters_sz = 80;
const int all_parameters_nb = 8;



void mpc_init();
void mpc_run(double** matrix);
void mpc_hover(int index);

void fill_x0(RocketSolver_params * p , int size);
void fill_xinit(RocketSolver_params * p , int size);
void fill_params(RocketSolver_params * p , int size, int nparam);
void set_altitude(RocketSolver_params * p , int size, int nparam, double altitude);

void read_data(double ** matrix);



double deg2rad(double degrees);



#endif

