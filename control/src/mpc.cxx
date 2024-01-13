#include "mpc.h"


#if simulation
// position subscriber
vehicle_local_position_groundtruth rocket_pose;
Subscriber_s<vehicle_local_position_groundtruthPubSubType,vehicle_local_position_groundtruth> vehicle_poseSub;

// attitude subscriber
vehicle_attitude_groundtruth rocket_attitude;
Subscriber_s<vehicle_attitude_groundtruthPubSubType,vehicle_attitude_groundtruth> vehicle_attitude_groundtruthSub;

// angular velocity subscriber
vehicle_angular_velocity_groundtruth rocket_angular;
Subscriber_s<vehicle_angular_velocity_groundtruthPubSubType,vehicle_angular_velocity_groundtruth> vehicle_angularSub;

#else

vehicle_odometry rocket_states;
Subscriber_s<vehicle_odometryPubSubType,vehicle_odometry> vehicle_odometrySub;

#endif 

//fsm subscriber
fsmDataOut fsmData;
Subscriber_s<fsmDataOutPubSubType, fsmDataOut> fsmDataSub;


// actuator publisher
actuator_controls_0* actuators_data = new actuator_controls_0;
actuator_controls_0__float_array_8 cmd = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
Publisher_s<actuator_controls_0PubSubType,actuator_controls_0> actuatorsPub;


// solver parameters
#ifdef FORCES
RocketSolver_extfunc extfunc_eval = &RocketSolver_adtool2forces;
RocketSolver_info solverInfo;
RocketSolver_output output;
RocketSolver_params solveparams;
RocketSolver_mem *mem = RocketSolver_internal_mem(0);
solver_int32_default status;
#else
	real_t * states = (real_t *) malloc(13*sizeof(real_t));
	real_t * controls = (real_t *) malloc(3*sizeof(real_t));
    /* Global variables used by the acado solver. */
    ACADOvariables acadoVariables;
    ACADOworkspace acadoWorkspace;
#endif

double xinit[] = {0, 0, 0,        0,0,0,          1,0,0,0,            0,0,0};

// vehicle parameters
double J1 = 0.03; 
double J2 = 0.03;
double J3 = 0.003;

double mass = 1.2;

double rGx =0 ;
double rGy =0 ;
double rGz =0.4;

double altitude = 2;

double deltaMax = deg2rad(15); //radians (TVC aperture)
double Tmax = mass*9.81*1.2; // Newtons

double k_m = 9.996e-7;
double w_max = 2650.0;






void mpc_init(){
    
    //std::cout << solveparams.xinit[0] << std::endl;
    
    
    // Subscribers
    fsmDataSub.init((char*)"fsmOut_Subscriber",(char*)"fsmDataOut_topic");
    
    #if simulation
        vehicle_poseSub.init((char*)"pose_Subscriber",(char*)"vehicle_local_position_groundtruthPubSubTopic");
        vehicle_angularSub.init((char*)"angular_Subscriber",(char*)"vehicle_angular_velocity_groundtruthPubSubTopic");
        vehicle_attitude_groundtruthSub.init((char*)"attitude_Subscriber",(char*)"vehicle_attitude_groundtruthPubSubTopic",mpc_iterate);
    #else
        vehicle_odometrySub.init((char*)"states_Subscriber",(char*)"vehicle_odometryPubSubTopic",mpc_iterate);
    #endif


    // Publishers
    actuatorsPub.init((char*)"actuators_publisher",(char*)"actuator_controls_0PubSubTopic");
    
    #ifdef FORCES
    fill_x0(&solveparams, x0_sz);
    fill_xinit(&solveparams, xinit_sz);
    fill_params(&solveparams , all_parameters_sz, all_parameters_nb);

    #else //ACADO
        acado_initializeSolver();
        fill_xinit_acado();    
        acado_preparationStep();
    #endif
    std::cout << "Control component initialized ... " << std::endl;
    sleep(2);
    
    #if simulation
        vehicle_attitude_groundtruthSub.spin();
    #else
        vehicle_odometrySub.spin();
    #endif
    
    }







void mpc_iterate(){
    
    fsmDataSub.get_data(&fsmData);
    #if verbose
        printf("[MPC] fsm state : %s \n",fsmData.state().c_str());
    #endif

    if(fsmData.state() == "hovering"){ 
            mpc_hover();
    }
    #if test_pid
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
        }
    #endif
    else if(fsmData.state() == "landing") {
        mpc_land();
    }
    else if(fsmData.state() == "disarming") {
        mpc_stop();
    }
}
















void mpc_hover(){
    
    #if verbose
    printf("Computing command \n");
    #endif

    // SENSORS FEEDBACK DATA

    #if simulation // SITL
    
        vehicle_poseSub.get_data(&rocket_pose);

        vehicle_attitude_groundtruthSub.get_data(&rocket_attitude);
        
        vehicle_angularSub.get_data(&rocket_angular);

        
        #ifdef FORCES

            set_altitude(&solveparams , all_parameters_sz, all_parameters_nb, 2.0);

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
        #else
            acadoVariables.x0[ 0 ] =  rocket_pose.x_();
            acadoVariables.x0[ 1 ] = -rocket_pose.y_();
            acadoVariables.x0[ 2 ] = -rocket_pose.z_();

            acadoVariables.x0[ 3 ] =  rocket_pose.vx_();
            acadoVariables.x0[ 4 ] = -rocket_pose.vy_();
            acadoVariables.x0[ 5 ] = -rocket_pose.vz_();

            acadoVariables.x0[ 6 ] =  rocket_attitude.q()[0];
            acadoVariables.x0[ 7 ] =  rocket_attitude.q()[1];
            acadoVariables.x0[ 8 ] = -rocket_attitude.q()[2];
            acadoVariables.x0[ 9 ] = -rocket_attitude.q()[3];

            acadoVariables.x0[ 10 ] =  rocket_angular.xyz()[0];
            acadoVariables.x0[ 11 ] = -rocket_angular.xyz()[1];
            acadoVariables.x0[ 12 ] = -rocket_angular.xyz()[2];
            

        #endif

    #else // IF NOT SIMULATION (REAL PHYSICAL HARDWARE)
        vehicle_odometrySub.get_data(&rocket_states);
        // the sign (-) is to convert NED frame to standard xyz frame 
        // where z is up, it is the frame used by the solver
        #ifdef FORCES
            solveparams.xinit[0] =  rocket_states.x_();
            solveparams.xinit[1] = -rocket_states.y_();
            solveparams.xinit[2] = -rocket_states.z_();
            
            solveparams.xinit[3] =  rocket_states.vx_();
            solveparams.xinit[4] = -rocket_states.vy_();
            solveparams.xinit[5] = -rocket_states.vz_();
            
            solveparams.xinit[6] =  rocket_states.q()[0];
            solveparams.xinit[7] =  rocket_states.q()[1];
            solveparams.xinit[8] = -rocket_states.q()[2];
            solveparams.xinit[9] = -rocket_states.q()[3];
            
            solveparams.xinit[10] =  rocket_states.rollspeed_();
            solveparams.xinit[11] = -rocket_states.pitchspeed_();
            solveparams.xinit[12] = -rocket_states.yawspeed_();
        #else
            
            acadoVariables.x0[0] =  rocket_states.x_();
            acadoVariables.x0[1] = -rocket_states.y_();
            acadoVariables.x0[2] = -rocket_states.z_();
            
            acadoVariables.x0[3] =  rocket_states.vx_();
            acadoVariables.x0[4] = -rocket_states.vy_();
            acadoVariables.x0[5] = -rocket_states.vz_();
            
            acadoVariables.x0[6] =  rocket_states.q()[0];
            acadoVariables.x0[7] =  rocket_states.q()[1];
            acadoVariables.x0[8] = -rocket_states.q()[2];
            acadoVariables.x0[9] = -rocket_states.q()[3];
            
            acadoVariables.x0[10] =  rocket_states.rollspeed_();
            acadoVariables.x0[11] = -rocket_states.pitchspeed_();
            acadoVariables.x0[12] = -rocket_states.yawspeed_();

        #endif
    #endif


    

    // MPC SOLVER INPUT COMPUTATION
    static uint64_t tic = timeSinceEpochMicrosec();
    #ifdef FORCES
        status = RocketSolver_solve(&solveparams , &output, &solverInfo , mem, NULL, extfunc_eval);
        Thrust2cmds(output.u[0],output.u[1],output.u[2], &cmd); 
    #else // ACADO
        /* Prepare for the next step. */
        acado_preparationStep();
        acado_feedbackStep( );
        controls=acado_getVariablesU();
        Thrust2cmds(controls[0],controls[1],controls[2], &cmd);
    #endif
    static uint64_t tac = timeSinceEpochMicrosec();
    
    
    // INPUT SENDING 

    // we prepare the control message
    actuators_data->control(cmd);
    actuators_data->timestamp_(timeSinceEpochMicrosec());	
    // we send the actuator message to the pixhawk
    actuatorsPub.publish(actuators_data);
    



    #if (verbose && simulation)
    printf("[MPC] pos \t");
    printf("\tx : %f\ty : %f\tz : %f\n",rocket_pose.x_(),
                                        -rocket_pose.y_(),
                                        -rocket_pose.z_());
    
    printf("[MPC] vel \t");
    printf("\tvx : %f\tvy : %f\tvz : %f\n",rocket_pose.vx_(),
                                           -rocket_pose.vy_(),
                                           -rocket_pose.vz_());
    
    printf("[MPC] att \t");
    printf("\tqs : %f\tqx : %f\tqy : %f\tqz : %f\n",rocket_attitude.q()[0],
                                                    rocket_attitude.q()[1],
                                                    -rocket_attitude.q()[2],
                                                    -rocket_attitude.q()[3]);


    static double r,p,y;
    quaternionToEuler(rocket_attitude.q()[0], rocket_attitude.q()[1], -rocket_attitude.q()[2],-rocket_attitude.q()[3], r, p, y);
    printf("\troll : %f\tpitch : %f\tyaw : %f\t\n",r,
                                                    p,
                                                    y);

      
    printf("[MPC] angular \t");
    printf("\twx : %f\twy : %f\twz : %f\n", rocket_angular.xyz()[0],
                                           -rocket_angular.xyz()[1],
                                           -rocket_angular.xyz()[2]);
    
    

    
        #ifdef FORCES
            printf("Rocket parameters \t");
            printf("\t J1= %f \t J3= %f \t m = %f \t rGz = %f \t altitude=  %f\n",solveparams.all_parameters[0],
                                                                                solveparams.all_parameters[2],
                                                                                solveparams.all_parameters[3],
                                                                                solveparams.all_parameters[6],
                                                                                solveparams.all_parameters[7]);
            
            printf("[MPC] control \t");
            printf("\tTx : %f\tTy : %f\tTz : %f\n",output.u[0],
                                                output.u[1],
                                                output.u[2]);  
            std::cout << "Solve status : " <<  status << std::endl;
        #endif
    
        std::cout << "Solve dt (us) : " <<  tac-tic <<  std::endl;
        
    #endif

}


























void mpc_land(){
        static bool reference_set = false;
        if (!reference_set){
            int i;
            /* Initialize the measurements/reference. */
            for (i = 0; i < NY * Nsteps; i+=NY)  {
                acadoVariables.y[ i+0 ] = 0.0; //x
                acadoVariables.y[ i+1 ] = 0.0; //y
                acadoVariables.y[ i+2 ] = 0.25; //z
                acadoVariables.y[ i+3 ] = 0.0; // pitch
                acadoVariables.y[ i+4 ] = 0.0; // yaw
                acadoVariables.y[ i+5 ] = 0.0; // omega
                acadoVariables.y[ i+6 ] = 0.0; // omega y 
                acadoVariables.y[ i+7 ] = 0.0; // tx
                acadoVariables.y[ i+8 ] = 0.0; // ty 
                acadoVariables.y[ i+9 ] = 0.0; // tz
            }
            for (i = 0; i < NYN; ++i)  acadoVariables.yN[ i ] = 0.0;
            acadoVariables.yN[ 2 ] = 0.25;

            reference_set = true;
        }            

        mpc_hover();    
}





void mpc_stop(){

    for(int i =0 ; i<8; i++){
        cmd[i] = 0;
    }
    
    actuators_data->control(cmd);
    actuators_data->timestamp_(timeSinceEpochMicrosec());	
    // we send the actuator message to the pixhawk
    actuatorsPub.publish(actuators_data);

}



uint64_t timeSinceEpochMicrosec() {
  using namespace std::chrono;
  return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}

double deg2rad(double degrees) {
    return degrees * ( M_PI / 180.0 );
}


#ifdef FORCES

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
#else

void fill_xinit_acado(){
    int i;
    for (i = 0; i < NX * (Nsteps + 1); i+=NX)  {
                acadoVariables.x[ i+0 ] = -1.0;
                acadoVariables.x[ i+1 ] = 1.0;
                acadoVariables.x[ i+2 ] = 0.0;

                acadoVariables.x[ i+3 ] = 0.0;
                acadoVariables.x[ i+4 ] = 0.0;
                acadoVariables.x[ i+5 ] = 0.0;

                acadoVariables.x[ i+6 ] = 0.707;
                acadoVariables.x[ i+7 ] = 0.0;
                acadoVariables.x[ i+8 ] = 0.0;
                acadoVariables.x[ i+9 ] = -0.707;

                acadoVariables.x[ i+10 ] = 0.0;
                acadoVariables.x[ i+11 ] = 0.0;
                acadoVariables.x[ i+12 ] = 0.0;
            }
            for (i = 0; i < NU * Nsteps; i+=NU)  {
                acadoVariables.u[ i ] = 0.;
                acadoVariables.u[ i+1 ] = 0.;	
                acadoVariables.u[ i+2 ] = 6;
                
            }
            /* Initialize the measurements/reference. */
            for (i = 0; i < NY * Nsteps; i+=NY)  {
                acadoVariables.y[ i+0 ] = 0.0; //x
                acadoVariables.y[ i+1 ] = 0.0; //y
                acadoVariables.y[ i+2 ] = 5.0; //z
                acadoVariables.y[ i+3 ] = 0.0; // pitch
                acadoVariables.y[ i+4 ] = 0.0; // yaw
                acadoVariables.y[ i+5 ] = 0.0; // omega
                acadoVariables.y[ i+6 ] = 0.0; // omega y 
                acadoVariables.y[ i+7 ] = 0.0; // tx
                acadoVariables.y[ i+8 ] = 0.0; // ty 
                acadoVariables.y[ i+9 ] = 0.0; // tz
            }
            

            for (i = 0; i < NYN; ++i)  acadoVariables.yN[ i ] = 0.0;
            acadoVariables.yN[ 2 ] = 5.0;


            /* MPC: initialize the current state feedback. */
        #if ACADO_INITIAL_STATE_FIXED	
                acadoVariables.x0[ 0 ] = -1.0;
                acadoVariables.x0[ 1 ] = 1.0;
                acadoVariables.x0[ 2 ] = 0.0;

                acadoVariables.x0[ 3 ] = 0.;
                acadoVariables.x0[ 4 ] = 0.;
                acadoVariables.x0[ 5 ] = 0.;

                acadoVariables.x0[ 6 ] = 0.7027;
                acadoVariables.x0[ 7 ] = 0.0;
                acadoVariables.x0[ 8 ] = 0.0;
                acadoVariables.x0[ 9 ] = -0.7115;

                acadoVariables.x0[ 10 ] = 0.;
                acadoVariables.x0[ 11 ] = 0.;
                acadoVariables.x0[ 12 ] = 0.;
        #endif

}
#endif


double magnitude_thrust(double thrustx, double thrusty, double thrustz){
    return sqrt(thrustx*thrustx + thrusty*thrusty + thrustz*thrustz);  
}

void Thrust2cmds(double thrustx, double thrusty, double thrustz , actuator_controls_0__float_array_8* cmd){
    static double tmp = 0;
    static double mag = 0;
    static double commandT = 0;
    mag = magnitude_thrust(thrustx,  thrusty, thrustz);
    
    mag = (mag > Tmax ?  Tmax : mag );

    // mag = k_m*w^2 => w = sqrt(mag/k_m) =>   cmd(%) = w/wmax =  sqrt(mag/k_m)/w_max
    // each motor supports mag/2 amount of thrust

    commandT = sqrt((mag/2)/k_m)/w_max;

    (*cmd)[0] = (float)(commandT);
    (*cmd)[1] = (float)(commandT);
    
    tmp = atan2(-(thrusty),thrustz)/deltaMax;
    tmp = (abs(tmp) > 1 ?  tmp/abs(tmp)*1 : tmp );
    (*cmd)[2] = tmp;
    
   
    tmp = asin(thrustx/mag)/deltaMax;
    tmp = (abs(tmp) > 1 ?  tmp/abs(tmp)*1 : tmp );
    (*cmd)[3] = tmp;


    #if verbose
        std::cout << "Thrust magnitude : "<< mag << std::endl;
        std::cout << "Thrustx : "<< thrustx << "\tThrusty : "<< thrusty  << "\tThrustz : "<< thrustz<< std::endl;
        std::cout << "thrust_cmd : " <<(*cmd)[0] << std::endl;
        std::cout << "cmd_th0 : " <<(*cmd)[2] << std::endl;
        std::cout << "cmd_th1 : " <<(*cmd)[3] << std::endl;
        std::cout << "-----------------------------------------------------------" << std::endl;
        
    #endif

    // force command
    #if pure_force
    (*cmd)[4] = (float)(thrustx/Tmax);
    (*cmd)[5] = (float)(thrusty/Tmax);
    (*cmd)[6] = (float)(thrustz/Tmax);
    #endif 

}


void quaternionToEuler(double w, double x, double y, double z, double &roll, double &pitch, double &yaw) {
    roll = (180/M_PI)*atan2(2*(w*x + y*z), 1 - 2*(x*x + y*y));
    pitch = (180/M_PI)*asin(2*(w*y - z*x));
    yaw = (180/M_PI)*atan2(2*(w*z + x*y), 1 - 2*(y*y + z*z));
}


