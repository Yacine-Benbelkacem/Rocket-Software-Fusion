#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#include "mpc.h"



int main(){

    printf("Starting MPC module ... \n");

    //std::thread control(mpc_init);
    mpc_init();
    //control.join();
    return 0;
}
