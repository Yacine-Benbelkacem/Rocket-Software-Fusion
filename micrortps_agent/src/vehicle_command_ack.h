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
 * @file vehicle_command_ack.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _VEHICLE_COMMAND_ACK_H_
#define _VEHICLE_COMMAND_ACK_H_

// TODO Poner en el contexto.

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(vehicle_command_ack_SOURCE)
#define vehicle_command_ack_DllAPI __declspec( dllexport )
#else
#define vehicle_command_ack_DllAPI __declspec( dllimport )
#endif // vehicle_command_ack_SOURCE
#else
#define vehicle_command_ack_DllAPI
#endif
#else
#define vehicle_command_ack_DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


const uint16_t vehicle_command_ack__ARM_AUTH_DENIED_REASON_GENERIC = 0;
const uint16_t vehicle_command_ack__ARM_AUTH_DENIED_REASON_NONE = 1;
const uint16_t vehicle_command_ack__ARM_AUTH_DENIED_REASON_INVALID_WAYPOINT = 2;
const uint16_t vehicle_command_ack__ARM_AUTH_DENIED_REASON_TIMEOUT = 3;
const uint16_t vehicle_command_ack__ARM_AUTH_DENIED_REASON_AIRSPACE_IN_USE = 4;
const uint16_t vehicle_command_ack__ARM_AUTH_DENIED_REASON_BAD_WEATHER = 5;
const uint8_t vehicle_command_ack__VEHICLE_RESULT_ACCEPTED = 0;
const uint8_t vehicle_command_ack__VEHICLE_RESULT_TEMPORARILY_REJECTED = 1;
const uint8_t vehicle_command_ack__VEHICLE_RESULT_DENIED = 2;
const uint8_t vehicle_command_ack__VEHICLE_RESULT_UNSUPPORTED = 3;
const uint8_t vehicle_command_ack__VEHICLE_RESULT_FAILED = 4;
const uint8_t vehicle_command_ack__VEHICLE_RESULT_IN_PROGRESS = 5;
const uint8_t vehicle_command_ack__ORB_QUEUE_LENGTH = 4;
/*!
 * @brief This class represents the structure vehicle_command_ack defined by the user in the IDL file.
 * @ingroup VEHICLE_COMMAND_ACK
 */
class vehicle_command_ack
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport vehicle_command_ack();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~vehicle_command_ack();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object vehicle_command_ack that will be copied.
     */
    eProsima_user_DllExport vehicle_command_ack(const vehicle_command_ack &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object vehicle_command_ack that will be copied.
     */
    eProsima_user_DllExport vehicle_command_ack(vehicle_command_ack &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object vehicle_command_ack that will be copied.
     */
    eProsima_user_DllExport vehicle_command_ack& operator=(const vehicle_command_ack &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object vehicle_command_ack that will be copied.
     */
    eProsima_user_DllExport vehicle_command_ack& operator=(vehicle_command_ack &&x);

    /*!
     * @brief This function sets a value in member timestamp_
     * @param _timestamp_ New value for member timestamp_
     */
    eProsima_user_DllExport void timestamp_(uint64_t _timestamp_);

    /*!
     * @brief This function returns the value of member timestamp_
     * @return Value of member timestamp_
     */
    eProsima_user_DllExport uint64_t timestamp_() const;

    /*!
     * @brief This function returns a reference to member timestamp_
     * @return Reference to member timestamp_
     */
    eProsima_user_DllExport uint64_t& timestamp_();

    /*!
     * @brief This function sets a value in member command_
     * @param _command_ New value for member command_
     */
    eProsima_user_DllExport void command_(uint32_t _command_);

    /*!
     * @brief This function returns the value of member command_
     * @return Value of member command_
     */
    eProsima_user_DllExport uint32_t command_() const;

    /*!
     * @brief This function returns a reference to member command_
     * @return Reference to member command_
     */
    eProsima_user_DllExport uint32_t& command_();

    /*!
     * @brief This function sets a value in member result_
     * @param _result_ New value for member result_
     */
    eProsima_user_DllExport void result_(uint8_t _result_);

    /*!
     * @brief This function returns the value of member result_
     * @return Value of member result_
     */
    eProsima_user_DllExport uint8_t result_() const;

    /*!
     * @brief This function returns a reference to member result_
     * @return Reference to member result_
     */
    eProsima_user_DllExport uint8_t& result_();

    /*!
     * @brief This function sets a value in member from_external_
     * @param _from_external_ New value for member from_external_
     */
    eProsima_user_DllExport void from_external_(bool _from_external_);

    /*!
     * @brief This function returns the value of member from_external_
     * @return Value of member from_external_
     */
    eProsima_user_DllExport bool from_external_() const;

    /*!
     * @brief This function returns a reference to member from_external_
     * @return Reference to member from_external_
     */
    eProsima_user_DllExport bool& from_external_();

    /*!
     * @brief This function sets a value in member result_param1_
     * @param _result_param1_ New value for member result_param1_
     */
    eProsima_user_DllExport void result_param1_(uint8_t _result_param1_);

    /*!
     * @brief This function returns the value of member result_param1_
     * @return Value of member result_param1_
     */
    eProsima_user_DllExport uint8_t result_param1_() const;

    /*!
     * @brief This function returns a reference to member result_param1_
     * @return Reference to member result_param1_
     */
    eProsima_user_DllExport uint8_t& result_param1_();

    /*!
     * @brief This function sets a value in member result_param2_
     * @param _result_param2_ New value for member result_param2_
     */
    eProsima_user_DllExport void result_param2_(int32_t _result_param2_);

    /*!
     * @brief This function returns the value of member result_param2_
     * @return Value of member result_param2_
     */
    eProsima_user_DllExport int32_t result_param2_() const;

    /*!
     * @brief This function returns a reference to member result_param2_
     * @return Reference to member result_param2_
     */
    eProsima_user_DllExport int32_t& result_param2_();

    /*!
     * @brief This function sets a value in member target_system_
     * @param _target_system_ New value for member target_system_
     */
    eProsima_user_DllExport void target_system_(uint8_t _target_system_);

    /*!
     * @brief This function returns the value of member target_system_
     * @return Value of member target_system_
     */
    eProsima_user_DllExport uint8_t target_system_() const;

    /*!
     * @brief This function returns a reference to member target_system_
     * @return Reference to member target_system_
     */
    eProsima_user_DllExport uint8_t& target_system_();

    /*!
     * @brief This function sets a value in member target_component_
     * @param _target_component_ New value for member target_component_
     */
    eProsima_user_DllExport void target_component_(uint8_t _target_component_);

    /*!
     * @brief This function returns the value of member target_component_
     * @return Value of member target_component_
     */
    eProsima_user_DllExport uint8_t target_component_() const;

    /*!
     * @brief This function returns a reference to member target_component_
     * @return Reference to member target_component_
     */
    eProsima_user_DllExport uint8_t& target_component_();


    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(const vehicle_command_ack& data, size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

private:
    uint64_t m_timestamp_;
    uint32_t m_command_;
    uint8_t m_result_;
    bool m_from_external_;
    uint8_t m_result_param1_;
    int32_t m_result_param2_;
    uint8_t m_target_system_;
    uint8_t m_target_component_;
};

#endif // _VEHICLE_COMMAND_ACK_H_