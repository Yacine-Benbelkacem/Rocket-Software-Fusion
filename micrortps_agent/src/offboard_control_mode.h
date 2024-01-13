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
 * @file offboard_control_mode.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _OFFBOARD_CONTROL_MODE_H_
#define _OFFBOARD_CONTROL_MODE_H_

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
#if defined(offboard_control_mode_SOURCE)
#define offboard_control_mode_DllAPI __declspec( dllexport )
#else
#define offboard_control_mode_DllAPI __declspec( dllimport )
#endif // offboard_control_mode_SOURCE
#else
#define offboard_control_mode_DllAPI
#endif
#else
#define offboard_control_mode_DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


/*!
 * @brief This class represents the structure offboard_control_mode defined by the user in the IDL file.
 * @ingroup OFFBOARD_CONTROL_MODE
 */
class offboard_control_mode
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport offboard_control_mode();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~offboard_control_mode();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object offboard_control_mode that will be copied.
     */
    eProsima_user_DllExport offboard_control_mode(const offboard_control_mode &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object offboard_control_mode that will be copied.
     */
    eProsima_user_DllExport offboard_control_mode(offboard_control_mode &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object offboard_control_mode that will be copied.
     */
    eProsima_user_DllExport offboard_control_mode& operator=(const offboard_control_mode &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object offboard_control_mode that will be copied.
     */
    eProsima_user_DllExport offboard_control_mode& operator=(offboard_control_mode &&x);

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
     * @brief This function sets a value in member position_
     * @param _position_ New value for member position_
     */
    eProsima_user_DllExport void position_(bool _position_);

    /*!
     * @brief This function returns the value of member position_
     * @return Value of member position_
     */
    eProsima_user_DllExport bool position_() const;

    /*!
     * @brief This function returns a reference to member position_
     * @return Reference to member position_
     */
    eProsima_user_DllExport bool& position_();

    /*!
     * @brief This function sets a value in member velocity_
     * @param _velocity_ New value for member velocity_
     */
    eProsima_user_DllExport void velocity_(bool _velocity_);

    /*!
     * @brief This function returns the value of member velocity_
     * @return Value of member velocity_
     */
    eProsima_user_DllExport bool velocity_() const;

    /*!
     * @brief This function returns a reference to member velocity_
     * @return Reference to member velocity_
     */
    eProsima_user_DllExport bool& velocity_();

    /*!
     * @brief This function sets a value in member acceleration_
     * @param _acceleration_ New value for member acceleration_
     */
    eProsima_user_DllExport void acceleration_(bool _acceleration_);

    /*!
     * @brief This function returns the value of member acceleration_
     * @return Value of member acceleration_
     */
    eProsima_user_DllExport bool acceleration_() const;

    /*!
     * @brief This function returns a reference to member acceleration_
     * @return Reference to member acceleration_
     */
    eProsima_user_DllExport bool& acceleration_();

    /*!
     * @brief This function sets a value in member attitude_
     * @param _attitude_ New value for member attitude_
     */
    eProsima_user_DllExport void attitude_(bool _attitude_);

    /*!
     * @brief This function returns the value of member attitude_
     * @return Value of member attitude_
     */
    eProsima_user_DllExport bool attitude_() const;

    /*!
     * @brief This function returns a reference to member attitude_
     * @return Reference to member attitude_
     */
    eProsima_user_DllExport bool& attitude_();

    /*!
     * @brief This function sets a value in member body_rate_
     * @param _body_rate_ New value for member body_rate_
     */
    eProsima_user_DllExport void body_rate_(bool _body_rate_);

    /*!
     * @brief This function returns the value of member body_rate_
     * @return Value of member body_rate_
     */
    eProsima_user_DllExport bool body_rate_() const;

    /*!
     * @brief This function returns a reference to member body_rate_
     * @return Reference to member body_rate_
     */
    eProsima_user_DllExport bool& body_rate_();


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
    eProsima_user_DllExport static size_t getCdrSerializedSize(const offboard_control_mode& data, size_t current_alignment = 0);


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
    bool m_position_;
    bool m_velocity_;
    bool m_acceleration_;
    bool m_attitude_;
    bool m_body_rate_;
};

#endif // _OFFBOARD_CONTROL_MODE_H_