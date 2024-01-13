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
 * @file vehicle_angular_velocity_groundtruth.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "vehicle_angular_velocity_groundtruth.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>


vehicle_angular_velocity_groundtruth::vehicle_angular_velocity_groundtruth()
{
    // m_timestamp_ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@158d2680
    m_timestamp_ = 0;
    // m_timestamp_sample_ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@77847718
    m_timestamp_sample_ = 0;
    // m_xyz com.eprosima.idl.parser.typecode.AliasTypeCode@7f3b84b8
    memset(&m_xyz, 0, (3) * 4);

}

vehicle_angular_velocity_groundtruth::~vehicle_angular_velocity_groundtruth()
{



}

vehicle_angular_velocity_groundtruth::vehicle_angular_velocity_groundtruth(const vehicle_angular_velocity_groundtruth &x)
{
    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_xyz = x.m_xyz;
}

vehicle_angular_velocity_groundtruth::vehicle_angular_velocity_groundtruth(vehicle_angular_velocity_groundtruth &&x)
{
    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_xyz = std::move(x.m_xyz);
}

vehicle_angular_velocity_groundtruth& vehicle_angular_velocity_groundtruth::operator=(const vehicle_angular_velocity_groundtruth &x)
{

    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_xyz = x.m_xyz;

    return *this;
}

vehicle_angular_velocity_groundtruth& vehicle_angular_velocity_groundtruth::operator=(vehicle_angular_velocity_groundtruth &&x)
{

    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_xyz = std::move(x.m_xyz);

    return *this;
}

size_t vehicle_angular_velocity_groundtruth::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

size_t vehicle_angular_velocity_groundtruth::getCdrSerializedSize(const vehicle_angular_velocity_groundtruth& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    if ((3) > 0)
    {
        current_alignment += ((3) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    }


    return current_alignment - initial_alignment;
}

void vehicle_angular_velocity_groundtruth::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_timestamp_;
    scdr << m_timestamp_sample_;
    scdr << m_xyz;

}

void vehicle_angular_velocity_groundtruth::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_timestamp_;
    dcdr >> m_timestamp_sample_;
    dcdr >> m_xyz;

}

/*!
 * @brief This function sets a value in member timestamp_
 * @param _timestamp_ New value for member timestamp_
 */
void vehicle_angular_velocity_groundtruth::timestamp_(uint64_t _timestamp_)
{
m_timestamp_ = _timestamp_;
}

/*!
 * @brief This function returns the value of member timestamp_
 * @return Value of member timestamp_
 */
uint64_t vehicle_angular_velocity_groundtruth::timestamp_() const
{
    return m_timestamp_;
}

/*!
 * @brief This function returns a reference to member timestamp_
 * @return Reference to member timestamp_
 */
uint64_t& vehicle_angular_velocity_groundtruth::timestamp_()
{
    return m_timestamp_;
}

/*!
 * @brief This function sets a value in member timestamp_sample_
 * @param _timestamp_sample_ New value for member timestamp_sample_
 */
void vehicle_angular_velocity_groundtruth::timestamp_sample_(uint64_t _timestamp_sample_)
{
m_timestamp_sample_ = _timestamp_sample_;
}

/*!
 * @brief This function returns the value of member timestamp_sample_
 * @return Value of member timestamp_sample_
 */
uint64_t vehicle_angular_velocity_groundtruth::timestamp_sample_() const
{
    return m_timestamp_sample_;
}

/*!
 * @brief This function returns a reference to member timestamp_sample_
 * @return Reference to member timestamp_sample_
 */
uint64_t& vehicle_angular_velocity_groundtruth::timestamp_sample_()
{
    return m_timestamp_sample_;
}

/*!
 * @brief This function copies the value in member xyz
 * @param _xyz New value to be copied in member xyz
 */
void vehicle_angular_velocity_groundtruth::xyz(const vehicle_angular_velocity_groundtruth__float_array_3 &_xyz)
{
m_xyz = _xyz;
}

/*!
 * @brief This function moves the value in member xyz
 * @param _xyz New value to be moved in member xyz
 */
void vehicle_angular_velocity_groundtruth::xyz(vehicle_angular_velocity_groundtruth__float_array_3 &&_xyz)
{
m_xyz = std::move(_xyz);
}

/*!
 * @brief This function returns a constant reference to member xyz
 * @return Constant reference to member xyz
 */
const vehicle_angular_velocity_groundtruth__float_array_3& vehicle_angular_velocity_groundtruth::xyz() const
{
    return m_xyz;
}

/*!
 * @brief This function returns a reference to member xyz
 * @return Reference to member xyz
 */
vehicle_angular_velocity_groundtruth__float_array_3& vehicle_angular_velocity_groundtruth::xyz()
{
    return m_xyz;
}

size_t vehicle_angular_velocity_groundtruth::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;






    return current_align;
}

bool vehicle_angular_velocity_groundtruth::isKeyDefined()
{
   return false;
}

void vehicle_angular_velocity_groundtruth::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
}
