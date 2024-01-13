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
 * @file actuator_controls.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "actuator_controls.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>





















actuator_controls::actuator_controls()
{
    // m_timestamp_ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3c19aaa5
    m_timestamp_ = 0;
    // m_timestamp_sample_ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3349e9bb
    m_timestamp_sample_ = 0;
    // m_control com.eprosima.idl.parser.typecode.AliasTypeCode@409bf450
    memset(&m_control, 0, (8) * 4);

}

actuator_controls::~actuator_controls()
{



}

actuator_controls::actuator_controls(const actuator_controls &x)
{
    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_control = x.m_control;
}

actuator_controls::actuator_controls(actuator_controls &&x)
{
    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_control = std::move(x.m_control);
}

actuator_controls& actuator_controls::operator=(const actuator_controls &x)
{

    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_control = x.m_control;

    return *this;
}

actuator_controls& actuator_controls::operator=(actuator_controls &&x)
{

    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_control = std::move(x.m_control);

    return *this;
}

size_t actuator_controls::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += ((8) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

size_t actuator_controls::getCdrSerializedSize(const actuator_controls& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    if ((8) > 0)
    {
        current_alignment += ((8) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    }


    return current_alignment - initial_alignment;
}

void actuator_controls::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_timestamp_;
    scdr << m_timestamp_sample_;
    scdr << m_control;

}

void actuator_controls::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_timestamp_;
    dcdr >> m_timestamp_sample_;
    dcdr >> m_control;

}

/*!
 * @brief This function sets a value in member timestamp_
 * @param _timestamp_ New value for member timestamp_
 */
void actuator_controls::timestamp_(uint64_t _timestamp_)
{
m_timestamp_ = _timestamp_;
}

/*!
 * @brief This function returns the value of member timestamp_
 * @return Value of member timestamp_
 */
uint64_t actuator_controls::timestamp_() const
{
    return m_timestamp_;
}

/*!
 * @brief This function returns a reference to member timestamp_
 * @return Reference to member timestamp_
 */
uint64_t& actuator_controls::timestamp_()
{
    return m_timestamp_;
}

/*!
 * @brief This function sets a value in member timestamp_sample_
 * @param _timestamp_sample_ New value for member timestamp_sample_
 */
void actuator_controls::timestamp_sample_(uint64_t _timestamp_sample_)
{
m_timestamp_sample_ = _timestamp_sample_;
}

/*!
 * @brief This function returns the value of member timestamp_sample_
 * @return Value of member timestamp_sample_
 */
uint64_t actuator_controls::timestamp_sample_() const
{
    return m_timestamp_sample_;
}

/*!
 * @brief This function returns a reference to member timestamp_sample_
 * @return Reference to member timestamp_sample_
 */
uint64_t& actuator_controls::timestamp_sample_()
{
    return m_timestamp_sample_;
}

/*!
 * @brief This function copies the value in member control
 * @param _control New value to be copied in member control
 */
void actuator_controls::control(const actuator_controls__float_array_8 &_control)
{
m_control = _control;
}

/*!
 * @brief This function moves the value in member control
 * @param _control New value to be moved in member control
 */
void actuator_controls::control(actuator_controls__float_array_8 &&_control)
{
m_control = std::move(_control);
}

/*!
 * @brief This function returns a constant reference to member control
 * @return Constant reference to member control
 */
const actuator_controls__float_array_8& actuator_controls::control() const
{
    return m_control;
}

/*!
 * @brief This function returns a reference to member control
 * @return Reference to member control
 */
actuator_controls__float_array_8& actuator_controls::control()
{
    return m_control;
}

size_t actuator_controls::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;






    return current_align;
}

bool actuator_controls::isKeyDefined()
{
   return false;
}

void actuator_controls::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
}
