#ifndef __FSM_H__
#define __FSM_H__

#include <stdio.h>
#include <cstring>
#include <tinyfsm.hpp>

#include <subscriber_s.h>
#include <publisher_s.h>

#include <messages/vehicle_local_position/vehicle_local_positionPubSubTypes.h>
#include <messages/fsmDataOut/fsmDataOutPubSubTypes.h>
#include <messages/vehicle_command/vehicle_commandPubSubTypes.h>


std::condition_variable cv_landing;
std::mutex mutex_landing;

Subscriber_s<vehicle_local_positionPubSubType, vehicle_local_position> vehiclePosSub;

Publisher_s<fsmDataOutPubSubType, fsmDataOut> fsmDataPub;

Publisher_s<vehicle_commandPubSubType, vehicle_command> commandsPub;

vehicle_command command;
fsmDataOut fsmData;
vehicle_local_position vehicle_position;


// 1 . EVENT DEFINITION
struct Start : tinyfsm::Event { };
struct Initialized : tinyfsm::Event {
  int value = 0;
};
class StartSQ_OK : tinyfsm::Event { };

class Disarm_Detected : tinyfsm::Event { };



// 2 . STATE MACHINE BASE DECLARATION
class RocketFSM
: public tinyfsm::Fsm<RocketFSM>
{
  public:
    /* default reaction for unhandled events */
    void react(tinyfsm::Event const &) { };

    /* pure virtual reaction (override required in all states) */
    virtual void react(Start const &);
    virtual void react(Initialized const &);
    virtual void react(Disarm_Detected const &);
    
    virtual void entry(void) { };  /* no entry actions */
    void exit(void) { };   /* no exit actions */

    
   
};

// 3 . STATES DECLARATION

class InitMachine : public RocketFSM{
    void entry() override;
    void react(Start const & i) override;

    void exit();
};

class Prompt : public RocketFSM{
  void react(Initialized const & i) override;
  void entry() override;
};


class Arming : public RocketFSM{
  void entry() override;
};


class Hovering : public RocketFSM{
  void entry() override;
};

class Landing : public RocketFSM{
  void react(Disarm_Detected const & i) override;
  void entry() override;
};

class Disarming : public RocketFSM{
  void entry() override;
};

void positionSub_callback();

#endif
