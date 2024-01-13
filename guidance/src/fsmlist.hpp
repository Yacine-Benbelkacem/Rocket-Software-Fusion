#ifndef FSMLIST_HPP_INCLUDED
#define FSMLIST_HPP_INCLUDED

#include <tinyfsm.hpp>

#include <fsm.hpp>


using fsm_list = tinyfsm::FsmList<RocketFSM>;


/** dispatch event to the state machine -- Custom Function */
template<typename E>
void send_event(E const & event)
{
  fsm_list::template dispatch<E>(event);
}


#endif
