#include "fsm.hpp"
#include "fsmlist.hpp"

//3 . STATES DECLARATION


void InitMachine::entry() {
        printf("[State : InitMachine] Entered InitMachine state \n");
    }

void InitMachine::react(Start const & i) {
    printf("Triggered State Initialization\n");



    if(fsmDataPub.init((char*)"fsmOut_Publisher",(char*)"fsmDataOut_topic")){
        printf("[State : InitMachine] FSM Data Publisher initialized. \n");
    }else{
        printf("[State : InitMachine] Couldn't initialize FSM Data Publisher.");
    }

    
    
    if(vehiclePosSub.init((char*)"Position_subscriber",(char*)"vehicle_local_positionPubSubTopic",positionSub_callback)){
        printf("[State : InitMachine] FVehicle Position Subscriber initialized. \n");
    }else{
        printf("[State : InitMachine] Couldn't initialize Vehicle Position Subscriber.");
    }


    if(commandsPub.init((char*)"Commands_publisher",(char*)"vehicle_commandPubSubTopic")){
        printf("[State : InitMachine] Commands Publisher initialized. \n");
    }else{
        printf("[State : InitMachine] Couldn't initialize Commands Publisher.");
    }


    sleep(2);


    transit<Prompt>();
    /*
    sleep(1);
    fsmData.state("init");
    fsmDataPub.publish(&fsmData);
    */
}



void Prompt::react(Initialized const & i) {
    printf("[State : Prompt] Entred Prompt State with initialized = %d ...\n", i.value);
    std::cout << "[Prompt] Is in prompt ? " << is_in_state<Prompt>() << std::endl;
}


void Prompt::entry() {

    fsmData.state("prompt");
    fsmDataPub.publish(&fsmData);
    printf("[State : Prompt] Entred Prompt State...\n");
    char choice;

    do{
        printf("[State : Prompt] Do you want to start launch sequence ? (y/n) : ");
        
        scanf("%c",&choice);
        getchar();
        printf("Your choice : %c \n", choice);    
    }while((choice != 'y') && (choice != 'n') );
    
    if (choice == 'y'){
        printf("[State : Prompt] Sequence start confirmed ... \n");
         
        transit<Arming>();
    }else{
        exit();
    }
}


void Arming::entry(){

    fsmData.state("arming");
    fsmDataPub.publish(&fsmData);
    printf("[State : Arming] Entred State Arming ...\n");

    command.target_system_(1);
    command.target_component_(1);
    
    command.command_( vehicle_command__VEHICLE_CMD_COMPONENT_ARM_DISARM);
    command.param1_(1);
    commandsPub.publish(&command);

    sleep(0.1);

    command.command_(vehicle_command__VEHICLE_CMD_DO_SET_MODE);
    command.param1_(220);
    commandsPub.publish(&command);
    
    printf("[State : Arming] Arm published ...\n");

    char choice;
    do{
        printf("[State : Arming] Fly ? (y/n)\n");
        scanf("%c",&choice);
        getchar();
        printf("Your choice : %c \n", choice);
    }while((choice != 'y') && (choice != 'n') );

    if (choice == 'y'){ 
        transit<Hovering>();
    }else{
        exit();
    }


}





void Hovering::entry(){
    fsmData.state("hovering");
    fsmDataPub.publish(&fsmData);
    printf("[State : Hovering] Entred State Hovering ...\n");


    char choice;
    do{
        printf("[State : Hovering] Land ? (y/n)\n");
        scanf("%c",&choice);
        getchar();
        printf("Your choice : %c \n", choice);
    }while((choice != 'y') && (choice != 'n') );

    if (choice == 'y'){ 
        transit<Landing>();
    }else{
        transit<Hovering>();
    }


}




void Landing::entry(){
    fsmData.state("landing");
    fsmDataPub.publish(&fsmData);
    printf("[State : landing] Entred State Landing ...\n");

    for(;;){
        std::unique_lock<std::mutex> lock(mutex_landing);
        cv_landing.wait(lock);
    }

}

void Landing::react(Disarm_Detected const & i){
    transit<Disarming>();
}

void Disarming::entry(){

    fsmData.state("disarming");
    fsmDataPub.publish(&fsmData);
    printf("[State : Disarming] Entred State disarming ...\n");

    command.target_system_(1);
    command.target_component_(1);
    
    command.command_( vehicle_command__VEHICLE_CMD_COMPONENT_ARM_DISARM);
    command.param1_(0);
    commandsPub.publish(&command);

    sleep(3);
    
    printf("[State : Disarming] Disarm published ...\n");

    exit();
}


// Virtual function default implementations
void RocketFSM::react(Initialized const & i){   

std::cout << "[Main] is in state InitMachine ? " << is_in_state<InitMachine>() << std::endl;
std::cout << "[Main] Arming state address " <<  &state<Arming>() << std::endl;
std::cout << "Current State " << current_state_ptr << std::endl;

    
}

void RocketFSM::react(Start const & i){

}

void RocketFSM::react(Disarm_Detected const & i){

}

void positionSub_callback(){
    if (RocketFSM::is_in_state<Landing>()){
        vehiclePosSub.get_data(&vehicle_position);   
        if (-vehicle_position.z_() < 0.3){

            send_event(Disarm_Detected());
        }
    }
}

FSM_INITIAL_STATE(RocketFSM, InitMachine);
