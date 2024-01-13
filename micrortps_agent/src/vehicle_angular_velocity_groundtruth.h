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
 * @file vehicle_angular_velocity_groundtruth.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _VEHICLE_ANGULAR_VELOCITY_GROUNDTRUTH_H_
#define _VEHICLE_ANGULAR_VELOCITY_GROUNDTRUTH_H_

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
#if defined(vehicle_angular_velocity_groundtruth_SOURCE)
#define vehicle_angular_velocity_groundtruth_DllAPI __declspec( dllexport )
#else
#define vehicle_angular_velocity_groundtruth_DllAPI __declspec( dllimport )
#endif // vehicle_angular_velocity_groundtruth_SOURCE
#else
#define vehicle_angular_velocity_groundtruth_DllAPI
#endif
#else
#define vehicle_angular_velocity_groundtruth_DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


typedef std::array<float, 3> vehicle_angular_velocity_groundtruth__float_array_3;
/*!
 * @brief This class represents the structure vehicle_angular_velocity_groundtruth defined by the user in the IDL file.
 * @ingroup VEHICLE_ANGULAR_VELOCITY_GROUNDTRUTH
 */
class vehicle_angular_velocity_groundtruth
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport vehicle_angular_velocity_groundtruth();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~vehicle_angular_velocity_groundtruth();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object vehicle_angular_velocity_groundtruth that will be copied.
     */
    eProsima_user_DllExport vehicle_angular_velocity_groundtruth(const vehicle_angular_velocity_groundtruth &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object vehicle_angular_velocity_groundtruth that will be copied.
     */
    eProsima_user_DllExport vehicle_angular_velocity_groundtruth(vehicle_angular_velocity_groundtruth &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object vehicle_angular_velocity_groundtruth that will be copied.
     */
    eProsima_user_DllExport vehicle_angular_velocity_groundtruth& operator=(const vehicle_angular_velocity_groundtruth &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object vehicle_angular_velocity_groundtruth that will be copied.
     */
    eProsima_user_DllExport vehicle_angular_velocity_groundtruth& operator=(vehicle_angular_velocity_groundtruth &&x);

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
     * @brief This function sets a value in member timestamp_sample_
     * @param _timestamp_sample_ New value for member timestamp_sample_
     */
    eProsima_user_DllExport void timestamp_sample_(uint64_t _timestamp_sample_);

    /*!
     * @brief This function returns the value of member timestamp_sample_
     * @return Value of member timestamp_sample_
     */
    eProsima_user_DllExport uint64_t timestamp_sample_() const;

    /*!
     * @brief This function returns a reference to member timestamp_sample_
     * @return Reference to member timestamp_sample_
     */
    eProsima_user_DllExport uint64_t& timestamp_sample_();

    /*!
     * @brief This function copies the value in member xyz
     * @param _xyz New value to be copied in member xyz
     */
    eProsima_user_DllExport void xyz(const vehicle_angular_velocity_groundtruth__float_array_3 &_xyz);

    /*!
     * @brief This function moves the value in member xyz
     * @param _xyz New value to be moved in member xyz
     */
    eProsima_user_DllExport void xyz(vehicle_angular_velocity_groundtruth__float_array_3 &&_xyz);

    /*!
     * @brief This function returns a constant reference to member xyz
     * @return Constant reference to member xyz
     */
    eProsima_user_DllExport const vehicle_angular_velocity_groundtruth__float_array_3& xyz() const;

    /*!
     * @brief This function returns a reference to member xyz
     * @return Reference to member xyz
     */
    eProsima_user_DllExport vehicle_angular_velocity_groundtruth__float_array_3& xyz();

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
    eProsima_user_DllExport static size_t getCdrSerializedSize(const vehicle_angular_velocity_groundtruth& data, size_t current_alignment = 0);


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
    uint64_t m_timestamp_sample_;
    vehicle_angular_velocity_groundtruth__float_array_3 m_xyz;
};

#endif // _VEHICLE_ANGULAR_VELOCITY_GROUNDTRUTH_H_