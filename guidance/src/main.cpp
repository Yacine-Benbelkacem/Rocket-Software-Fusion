#include <array>

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "fsm.hpp"
#include "fsm.cpp"
#include <pthread.h>
#include <thread>
#include <chrono>




/*
void* event_handler(void * no_param){
    // Event instanciations

    printf("[Event handler] : Event handler started \n");

    printf("[Event handler] : Sending Start Signal ... \n");
    send_event(Start());
    printf("[Event handler] : Start Signal  Sent... \n");
    //usleep(5*1000*1000);
    printf("[Event handler] : Sending Initialised Signal ...\n");
    send_event(Initialized());
    printf("[Event handler] : Initialized signal sent .. \n");
    
    return NULL;

}
*/

void* manage_fsm(void * no_param){
    
    printf("[Manage FSM] : manage_fsm started \n");
    
    RocketFSM sm;

    sm.start();
    
    printf("State Machine is starting ...\n");
    send_event(Start());

    return NULL;
}


int main(){

/*   
    pthread_t fsm_thread;
    pthread_t event_handler_thread;

    int status; 
    int policy;

    pthread_attr_t attr;
    sched_param param;

    pthread_attr_init(&attr);

    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    

    pthread_attr_getschedparam(&attr,
                               &param);
    param.sched_priority = 40;
    printf("Sched priority %d \n",param.sched_priority);
    pthread_attr_setschedparam(&attr,&param);
    
    


    printf("[main] Starting FSM thread \n");
  */
    
    //status = pthread_create(&fsm_thread, &attr,  &manage_fsm, NULL);

    manage_fsm(NULL);

/*
    pthread_attr_init(&attr);

    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    
    pthread_attr_getschedparam(&attr,
                               &param);
    param.sched_priority = 45;
    pthread_attr_setschedparam(&attr,&param);
 
    printf("[main] Starting Event handler thread \n");
    status = pthread_create(&event_handler_thread, &attr, &event_handler, NULL);
*/  
    



    printf("[Main] Waiting for join ... \n");
    //status = pthread_join(fsm_thread, NULL);
    
    usleep(1*1000*1000);
    
    // Destroy the Publishers/Subscribers 
    
    fsmDataPub.~Publisher_s();
    commandsPub.~Publisher_s();
    
}
