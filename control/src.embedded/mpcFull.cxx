#include "mpc.h"



// position subscriber
vehicle_local_position_groundtruth rocket_pose;
Subscriber_s<vehicle_local_position_groundtruthPubSubType,vehicle_local_position_groundtruth> vehicle_poseSub;

// attitude subscriber
vehicle_attitude_groundtruth rocket_attitude;
Subscriber_s<vehicle_attitude_groundtruthPubSubType,vehicle_attitude_groundtruth> vehicle_attitude_groundtruthSub;

// angular velocity subscriber
vehicle_angular_velocity_groundtruth rocket_angular;
Subscriber_s<vehicle_angular_velocity_groundtruthPubSubType,vehicle_angular_velocity_groundtruth> vehicle_angularSub;

//fsm subscriber
fsmDataOut fsmData;
Subscriber_s<fsmDataOutPubSubType, fsmDataOut> fsmDataSub;


// actuator publisher
actuator_controls_0* actuators_data = new actuator_controls_0;
actuator_controls_0__float_array_8 cmd = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
Publisher_s<actuator_controls_0PubSubType,actuator_controls_0> actuatorsPub;


// solver parameters
RocketSolver_extfunc extfunc_eval = &RocketSolver_adtool2forces;
RocketSolver_info solverInfo;
RocketSolver_output output;
RocketSolver_params solveparams;
RocketSolver_mem *mem = RocketSolver_internal_mem(0);
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

double deltaMax = deg2rad(15); //radians (TVC aperture)
double Tmax = 13; // Newtons

double k_m = 9.286e-7;
double w_max = 2650.0;

void mpc_init(){
    
    //std::cout << solveparams.xinit[0] << std::endl;
    
    // Subscribers
    vehicle_poseSub.init((char*)"pose_Subscriber",(char*)"vehicle_local_position_groundtruthPubSubTopic");
    fsmDataSub.init((char*)"fsmOut_Subscriber",(char*)"fsmDataOut_topic");
    vehicle_angularSub.init((char*)"angular_Subscriber",(char*)"vehicle_angular_velocity_groundtruthPubSubTopic");
    vehicle_attitude_groundtruthSub.init((char*)"attitude_Subscriber",(char*)"vehicle_attitude_groundtruthPubSubTopic");

    // Publishers
    actuatorsPub.init((char*)"actuators_publisher",(char*)"actuator_controls_0PubSubTopic");
    
    fill_x0(&solveparams, x0_sz);
    fill_xinit(&solveparams, xinit_sz);
    fill_params(&solveparams , all_parameters_sz, all_parameters_nb);
    
    sleep(2);
}





void mpc_run(){

    //init actuators
    for(int i=0; i<2; i++){	
        actuators_data->control(cmd);
        actuators_data->timestamp_(timeSinceEpochMicrosec());
        actuatorsPub.publish(actuators_data);
        sleep(1);
    }

    while(1){
        fsmDataSub.get_data(&fsmData);

        printf("[MPC] fsm state : %s \n",fsmData.state().c_str());
        
        if(fsmData.state() == "hovering"){ 
            mpc_hover();
        }
        /*
        else if(fsmData.state() == "arming"){
            static float tmp = 1.0;
            static float kp = 1.0;
            static float ki = 0.1;
            static float kd = 0.01;
            
            printf("test PID (0-1.0): \t");
            scanf("%f %f %f %f",&tmp,&kp,&ki,&kd);
        
            cmd[0] = 0.0;
            cmd[1] = 0.0;
    
            cmd[2] = tmp;  //servo axis 0
            cmd[3] = tmp; // servo axis 1
            cmd[4] = kp; 
            cmd[5] = ki;           
            cmd[6] = kd;      
            
            printf("CMD = %f \n",cmd[2]);
            
            actuators_data->control(cmd);
            actuators_data->timestamp_(timeSinceEpochMicrosec());	
            actuatorsPub.publish(actuators_data);
        }*/
        else{

        }

        usleep(1000*50);
    }
}
















void mpc_hover(){
    static double r,p,y;
    printf("Computing hover command \n");
    
    // SENSORS INPUTS
    vehicle_poseSub.get_data(&rocket_pose);
    vehicle_attitude_groundtruthSub.get_data(&rocket_attitude);
    vehicle_angularSub.get_data(&rocket_angular);


    printf("[MPC] pos \t");
    printf("\tx : %f\ty : %f\tz : %f\n",rocket_pose.x_(),
                                        -rocket_pose.y_(),
                                        -rocket_pose.z_());
    
    printf("[MPC] vel \t");
    printf("\tvx : %f\tvy : %f\tvz : %f\n",rocket_pose.vx_(),
                                           -rocket_pose.vy_(),
                                           -rocket_pose.vz_());
    
    printf("[MPC] att \t");
    /*
    printf("\tqs : %f\tqx : %f\tqy : %f\tqz : %f\n",rocket_attitude.q()[0],
                                                    rocket_attitude.q()[1],
                                                    -rocket_attitude.q()[2],
                                                    -rocket_attitude.q()[3]);
    */

   quaternionToEuler(rocket_attitude.q()[0], rocket_attitude.q()[1], -rocket_attitude.q()[2],-rocket_attitude.q()[3], r, p, y);
    printf("\troll : %f\tpitch : %f\tyaw : %f\t\n",r,
                                                    p,
                                                    y);

    /*printf("\tqs : %f\tqx : %f\tqy : %f\tqz : %f\n",rocket_attitude.delta_q_reset()[0],
                                                    rocket_attitude.delta_q_reset()[1],
                                                    rocket_attitude.delta_q_reset()[2],
                                                    rocket_attitude.delta_q_reset()[3]);*/
      
    printf("[MPC] angular \t");
    printf("\twx : %f\twy : %f\twz : %f\n", rocket_angular.xyz()[0],
                                           -rocket_angular.xyz()[1],
                                           -rocket_angular.xyz()[2]);
    
    
    set_altitude(&solveparams , all_parameters_sz, all_parameters_nb, 2.0);

    printf("Rocket parameters \t");
    printf("\t J1= %f \t J3= %f \t m = %f \t rGz = %f \t altitude=  %f\n",solveparams.all_parameters[0],
                                                                          solveparams.all_parameters[2],
                                                                          solveparams.all_parameters[3],
                                                                          solveparams.all_parameters[6],
                                                                          solveparams.all_parameters[7]);
    
    
    solveparams.xinit[0] = rocket_pose.x_();
    solveparams.xinit[1] = -rocket_pose.y_();
    solveparams.xinit[2] = -rocket_pose.z_();
    
    solveparams.xinit[3] = rocket_pose.vx_();
    solveparams.xinit[4] = -rocket_pose.vy_();
    solveparams.xinit[5] = -rocket_pose.vz_();
    
    solveparams.xinit[6] = rocket_attitude.q()[0];
    solveparams.xinit[7] = rocket_attitude.q()[1];
    solveparams.xinit[8] = -rocket_attitude.q()[2];
    solveparams.xinit[9] = -rocket_attitude.q()[3];
    
    solveparams.xinit[10] =  rocket_angular.xyz()[0];
    solveparams.xinit[11] = -rocket_angular.xyz()[1];
    solveparams.xinit[12] = -rocket_angular.xyz()[2];
    
    // MPC SOLVER
    static uint64_t tic = timeSinceEpochMicrosec();
    
    status = RocketSolver_solve(&solveparams , &output, &solverInfo , mem, NULL, extfunc_eval);
    
    static uint64_t tac = timeSinceEpochMicrosec();

    std::cout << "Solve dt (us) : " <<  tac-tic << " |    FORCES estimation (us) : " <<solverInfo.solvetime<< std::endl;
    std::cout << "Solve status : " <<  status << std::endl;



    printf("[MPC] control \t");
    printf("\tTx : %f\tTy : %f\tTz : %f\n",output.u[0],
                                           output.u[1],
                                           output.u[2]);    
              
        
	    static float tmp = 1.0;
	    /*
	    tmp *= (-1.0);
            cmd[0] = 0.0;
            cmd[1] = 0.0;
            cmd[2] = 0.0;  //servo axis 0
            cmd[3] = 1.0; // servo axis 1
          */
        Thrust2cmds(output, &cmd);
        
        actuators_data->control(cmd);
        actuators_data->timestamp_(timeSinceEpochMicrosec());	
        actuatorsPub.publish(actuators_data);

}












void mpc_ascend(){

}













void mpc_land(){

}









uint64_t timeSinceEpochMicrosec() {
  using namespace std::chrono;
  return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
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


double magnitude_thrust(RocketSolver_output thrust){
    return sqrt(thrust.u[0]*thrust.u[0] + thrust.u[1]*thrust.u[1] + thrust.u[2]*thrust.u[2]);  
}

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


void quaternionToEuler(double w, double x, double y, double z, double &roll, double &pitch, double &yaw) {
    roll = (180/M_PI)*atan2(2*(w*x + y*z), 1 - 2*(x*x + y*y));
    pitch = (180/M_PI)*asin(2*(w*y - z*x));
    yaw = (180/M_PI)*atan2(2*(w*z + x*y), 1 - 2*(y*y + z*z));
}
