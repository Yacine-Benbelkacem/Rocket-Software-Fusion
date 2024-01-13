#define _GNU_SOURCE
#include "mpc.h"



// solver parameters

const int x0_sz = 480;
const int xinit_sz = 13;
const int all_parameters_sz = 240;
const int all_parameters_nb = 8;




RocketSolver_extfunc extfunc_eval = &RocketSolver_adtool2forces;
RocketSolver_info solverInfo;
RocketSolver_output output;
RocketSolver_params solveparams;
RocketSolver_mem *mem;
solver_int32_default status;

double xinit[] = {0, 0, 0,        0,0,0,          1,0,0,0,            0,0,0};

double J1 = 0.054; 
double J2 = 0.054;
double J3 = 0.0018;

double mass = 1.0;

double rGx =0 ;
double rGy =0 ;
double rGz =0.4;

double altitude = 2;

double deltaMax = 0.17;//deg2rad(15); //radians (TVC aperture)
double Tmax = 13; // Newtons

double k_m = 9.286e-7;
double w_max = 2650.0;

void mpc_init(){
    
    mem = RocketSolver_internal_mem(0);
    fill_x0(&solveparams, x0_sz);
    fill_xinit(&solveparams, xinit_sz);
    fill_params(&solveparams , all_parameters_sz, all_parameters_nb);
    
    sleep(2);
    printf("Solver filled \n");
}





void mpc_run(){

    printf("launched run \n");
    
}
















void mpc_hover(){
    
    printf("Computing hover command \n");
    
    // SENSORS INPUTS
    
    set_altitude(&solveparams , all_parameters_sz, all_parameters_nb, 2.0);

    printf("Rocket parameters \t");
    printf("\t J1= %f \t J3= %f \t m = %f \t rGz = %f \t altitude=  %f\n",solveparams.all_parameters[0],
                                                                          solveparams.all_parameters[2],
                                                                          solveparams.all_parameters[3],
                                                                          solveparams.all_parameters[6],
                                                                          solveparams.all_parameters[7]);
    
    
    solveparams.xinit[0] = 0;
    solveparams.xinit[1] = 0;
    solveparams.xinit[2] = 0;
    
    solveparams.xinit[3] = 0;
    solveparams.xinit[4] = 0;
    solveparams.xinit[5] = 0;
    
    solveparams.xinit[6] = 1;
    solveparams.xinit[7] = 0;
    solveparams.xinit[8] = 0;
    solveparams.xinit[9] = 0;
    
    solveparams.xinit[10] = 0;
    solveparams.xinit[11] = 0;
    solveparams.xinit[12] = 0;
    
        
    status = RocketSolver_solve(&solveparams , &output, &solverInfo , mem, NULL, extfunc_eval);
    
    //status = RocketSolver_solve(NULL , NULL, NULL , NULL, NULL, NULL);
    
    // MPC SOLVER
/*
    static uint64_t tic = timeSinceEpochMicrosec();
    
    
    
    static uint64_t tac = timeSinceEpochMicrosec();

    std::cout << "Solve dt (us) : " <<  tac-tic << " |    FORCES estimation (us) : " <<solverInfo.solvetime<< std::endl;
    std::cout << "Solve status : " <<  status << std::endl;
*/

}












void mpc_ascend(){

}













void mpc_land(){

}








/*
uint64_t timeSinceEpochMicrosec() {
  using namespace std::chrono;
  return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}*/
/*
double deg2rad(double degrees) {
    return degrees * ( M_PI / 180.0 );
}*/


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


double magnitude_thrust(RocketSolver_output thrust){
    return sqrt(thrust.u[0]*thrust.u[0] + thrust.u[1]*thrust.u[1] + thrust.u[2]*thrust.u[2]);  
}

/*
void Thrust2cmds(RocketSolver_output thrust , actuator_controls_0__float_array_8* cmd){
    static double tmp = 0;
    static double mag = 0;
    static double commandT = 0;
    mag = magnitude_thrust(thrust);
    std::cout << "Thrust magnitude : "<< mag << std::endl;
    mag = (mag > Tmax ?  Tmax : mag );

    // mag = k_m*w^2 => w = sqrt(mag/k_m) =>   cmd(%) = w/wmax =  sqrt(mag/k_m)/w_max

    commandT = sqrt((mag/2)/k_m)/w_max;

    (*cmd)[0] = (float)(commandT);
    (*cmd)[1] = (float)(commandT);
    
    tmp = atan2(-(thrust.u[1]),thrust.u[2])/deltaMax;
    tmp = (abs(tmp) > 1 ?  tmp/abs(tmp)*1 : tmp );
    (*cmd)[2] = tmp;
    std::cout << "cmd_th0 : " <<(*cmd)[2] << std::endl;
   
    tmp = asin(thrust.u[0]/mag);
    std::cout << "cmd_angle : " << tmp << std::endl;
    tmp /= deltaMax;
    tmp = (abs(tmp) > 1 ?  tmp/abs(tmp)*1 : tmp );
    (*cmd)[3] = tmp;
    std::cout << "cmd_th1 : " <<(*cmd)[3] << std::endl;

    // force command
    //(*cmd)[4] = (float)(thrust.u[0]/Tmax);
    //(*cmd)[5] = (float)(thrust.u[1]/Tmax);
    //(*cmd)[6] = (float)(thrust.u[2]/Tmax);


}

*/
/*
void quaternionToEuler(double w, double x, double y, double z, double &roll, double &pitch, double &yaw) {
    roll = (180/M_PI)*atan2(2*(w*x + y*z), 1 - 2*(x*x + y*y));
    pitch = (180/M_PI)*asin(2*(w*y - z*x));
    yaw = (180/M_PI)*atan2(2*(w*z + x*y), 1 - 2*(y*y + z*z));
}*/
