#include "mpc.h"



// solver parameters
RocketSolver_extfunc extfunc_eval = &RocketSolver_adtool2forces;
RocketSolver_info solverInfo;
RocketSolver_output output;
RocketSolver_params solveparams;
RocketSolver_mem *mem = RocketSolver_internal_mem(0);
solver_int32_default status;




double J1 = 0.064; 
double J2 = 0.064;
double J3 = 0.012;

double mass = 1.0;

double rGx =0 ;
double rGy =0 ;
double rGz =0.3;

double altitude = 5;


double xinit[] = {0, 0, 10,        0,0,0,          1,0,0,0,            0,0,0};


void mpc_init(){
    
    fill_x0(&solveparams, x0_sz);
    fill_xinit(&solveparams, xinit_sz);
    fill_params(&solveparams , all_parameters_sz, all_parameters_nb);
    
    sleep(1);
}




void mpc_run(){

    
    int i = 0;
    
    while(i < ROWS){
   
        // calculate     
        mpc_hover(i);
        
        i++;
        usleep(1000*100);
    }
}





void mpc_hover(int index){
    
    static clock_t tic, tac;

    set_altitude(&solveparams , all_parameters_sz, all_parameters_nb, 5.0);

    solveparams.xinit[0] = matrix[index][0];
    solveparams.xinit[1] = matrix[index][1];
    solveparams.xinit[2] = matrix[index][2];
    
    solveparams.xinit[3] = matrix[index][3];
    solveparams.xinit[4] = matrix[index][4];
    solveparams.xinit[5] = matrix[index][5];
    
    solveparams.xinit[6] = matrix[index][6];
    solveparams.xinit[7] = matrix[index][7];
    solveparams.xinit[8] = matrix[index][8];
    solveparams.xinit[9] = matrix[index][9];
    
    solveparams.xinit[10] = matrix[index][10];
    solveparams.xinit[11] = matrix[index][11]
    solveparams.xinit[12] = matrix[index][12];
    
    // MPC SOLVER
    tic = clock();
    
    status = RocketSolver_solve(&solveparams , &output, &solverInfo , mem, NULL, extfunc_eval);
    
    tac = clock();

    printf("%f\n",(double)(tac - tic)*1000000 / CLOCKS_PER_SEC);
    printf("Solve status : %d \n",status);


}























double deg2rad(double degrees) {
    return degrees * ( M_PI / 180.0 );
}


void fill_x0(RocketSolver_params * p , int size){
    for (int i = 0 ; i <size; i++){
        p->x0[i] = 0.0;
    };
}


void fill_xinit(RocketSolver_params * p ,  int nparam){
    for (int i = 0 ; i <nparam; i++){
        p->xinit[i] = xinit[i];
    };
}

void fill_params(RocketSolver_params * p , int size, int nparam){
    for (int i = 0 ; i <size; i+=nparam){
            p->all_parameters[i+0] = J1;
            p->all_parameters[i+1] = J2;
            p->all_parameters[i+2] = J3;
            p->all_parameters[i+3] = mass;
            p->all_parameters[i+4] = rGx;
            p->all_parameters[i+5] = rGy;
            p->all_parameters[i+6] = rGz;
            p->all_parameters[i+7] = altitude;

    };
    
    
}

void set_altitude(RocketSolver_params * p , int size, int nparam, double alt){
    for (int i = 0 ; i <size; i+=nparam){
            p->all_parameters[i+7] = alt;
    };
}


void read_data(double * matrix){

    FILE* csv_file = fopen("data.csv", "r"); // Open file in read mode

    if (csv_file == NULL) {
        printf("Error opening file!");
        return 1;
    }


    int row = 0; // Counter for the current row

    while (row < ROWS && fscanf(csv_file, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf",
           &matrix[row][0], &matrix[row][1], &matrix[row][2], &matrix[row][3], &matrix[row][4],
           &matrix[row][5], &matrix[row][6], &matrix[row][7], &matrix[row][8], &matrix[row][9],
           &matrix[row][10], &matrix[row][11], &matrix[row][12]) == 13) {

        // Increment the row counter
        row++;
    }


    fclose(csv_file); // Don't forget to close the file when you're done!


}







