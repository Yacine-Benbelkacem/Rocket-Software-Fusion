// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file Publisher_s.h
 * This header file contains the declaration of the publisher functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _S_PUBLISHER_H_
#define _S_PUBLISHER_H_

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/publisher/PublisherListener.h>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/attributes/PublisherAttributes.h>

#include <fastrtps/Domain.h>
#include <fastrtps/TopicDataType.h>

#include <thread>
#include <chrono>




template<class T, class S>
class Publisher_s
{
public:
	Publisher_s();
	virtual ~Publisher_s();
	bool init(char* const node_name_,char* const topic_name_);
	void publish(S* st);
private:
	eprosima::fastrtps::Participant *mp_participant;
	eprosima::fastrtps::Publisher *mp_publisher;

    

	class PubListener : public eprosima::fastrtps::PublisherListener
	{
	public:
		PubListener() : n_matched(0){};
		~PubListener(){};
		void onPublicationMatched(eprosima::fastrtps::Publisher* pub,eprosima::fastrtps::rtps::MatchingInfo& info);
		int n_matched;
	} m_listener;
	T myType;
};



//// IMPLEMENTATION /////////////////



using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

template<class T, class S>
Publisher_s<T,S>::Publisher_s() : mp_participant(nullptr), mp_publisher(nullptr) {}

template<class T, class S>
Publisher_s<T,S>::~Publisher_s() {	Domain::removeParticipant(mp_participant);}

template<class T, class S>
bool Publisher_s<T,S>::init(char* const node_name_,char* const topic_name_)
{
    // Create RTPSParticipant
    ParticipantAttributes PParam;
    PParam.rtps.setName(node_name_);  //You can put here the name you want
    mp_participant = Domain::createParticipant(PParam);
    if(mp_participant == nullptr)
    {
        return false;
    }

    //Register the type

    Domain::registerType(mp_participant, static_cast<TopicDataType*>(&myType));

    // Create Publisher

    PublisherAttributes Wparam;
    Wparam.topic.topicKind = NO_KEY;
    Wparam.topic.topicDataType = myType.getName();  //This type MUST be registered
    Wparam.topic.topicName = topic_name_;

    mp_publisher = Domain::createPublisher(mp_participant,Wparam,static_cast<PublisherListener*>(&m_listener));

    if(mp_publisher == nullptr)
    {
        std::cout << "Error creating publisher : " << *topic_name_<< std::endl;
        return false;
    }

    //std::cout << "Publisher created, waiting for Subscribers." << std::endl;
    return true;
}

template<class T, class S>
void Publisher_s<T,S>::PubListener::onPublicationMatched(Publisher* pub,MatchingInfo& info)
{
    (void)pub;

    if (info.status == MATCHED_MATCHING)
    {
        n_matched++;
        std::cout << "Publisher matched" << std::endl;
    }
    else
    {
        n_matched--;
        std::cout << "Publisher unmatched" << std::endl;
    }
}
template<class T, class S>
void Publisher_s<T,S>::publish(S* st)
{

    mp_publisher->write(st);
    
}






#endif // _S_PUBLISHER_H_
