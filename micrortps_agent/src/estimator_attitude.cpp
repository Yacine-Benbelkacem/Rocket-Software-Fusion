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
 * @file estimator_attitude.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "estimator_attitude.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>


estimator_attitude::estimator_attitude()
{
    // m_timestamp_ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2b662a77
    m_timestamp_ = 0;
    // m_timestamp_sample_ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7f0eb4b4
    m_timestamp_sample_ = 0;
    // m_q com.eprosima.idl.parser.typecode.AliasTypeCode@5c33f1a9
    memset(&m_q, 0, (4) * 4);
    // m_delta_q_reset com.eprosima.idl.parser.typecode.AliasTypeCode@5c33f1a9
    memset(&m_delta_q_reset, 0, (4) * 4);
    // m_quat_reset_counter_ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1623b78d
    m_quat_reset_counter_ = 0;

}

estimator_attitude::~estimator_attitude()
{





}

estimator_attitude::estimator_attitude(const estimator_attitude &x)
{
    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_q = x.m_q;
    m_delta_q_reset = x.m_delta_q_reset;
    m_quat_reset_counter_ = x.m_quat_reset_counter_;
}

estimator_attitude::estimator_attitude(estimator_attitude &&x)
{
    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_q = std::move(x.m_q);
    m_delta_q_reset = std::move(x.m_delta_q_reset);
    m_quat_reset_counter_ = x.m_quat_reset_counter_;
}

estimator_attitude& estimator_attitude::operator=(const estimator_attitude &x)
{

    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_q = x.m_q;
    m_delta_q_reset = x.m_delta_q_reset;
    m_quat_reset_counter_ = x.m_quat_reset_counter_;

    return *this;
}

estimator_attitude& estimator_attitude::operator=(estimator_attitude &&x)
{

    m_timestamp_ = x.m_timestamp_;
    m_timestamp_sample_ = x.m_timestamp_sample_;
    m_q = std::move(x.m_q);
    m_delta_q_reset = std::move(x.m_delta_q_reset);
    m_quat_reset_counter_ = x.m_quat_reset_counter_;

    return *this;
}

size_t estimator_attitude::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += ((4) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += ((4) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t estimator_attitude::getCdrSerializedSize(const estimator_attitude& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    if ((4) > 0)
    {
        current_alignment += ((4) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    }

    if ((4) > 0)
    {
        current_alignment += ((4) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    }

    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void estimator_attitude::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_timestamp_;
    scdr << m_timestamp_sample_;
    scdr << m_q;

    scdr << m_delta_q_reset;

    scdr << m_quat_reset_counter_;
}

void estimator_attitude::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_timestamp_;
    dcdr >> m_timestamp_sample_;
    dcdr >> m_q;

    dcdr >> m_delta_q_reset;

    dcdr >> m_quat_reset_counter_;
}

/*!
 * @brief This function sets a value in member timestamp_
 * @param _timestamp_ New value for member timestamp_
 */
void estimator_attitude::timestamp_(uint64_t _timestamp_)
{
m_timestamp_ = _timestamp_;
}

/*!
 * @brief This function returns the value of member timestamp_
 * @return Value of member timestamp_
 */
uint64_t estimator_attitude::timestamp_() const
{
    return m_timestamp_;
}

/*!
 * @brief This function returns a reference to member timestamp_
 * @return Reference to member timestamp_
 */
uint64_t& estimator_attitude::timestamp_()
{
    return m_timestamp_;
}

/*!
 * @brief This function sets a value in member timestamp_sample_
 * @param _timestamp_sample_ New value for member timestamp_sample_
 */
void estimator_attitude::timestamp_sample_(uint64_t _timestamp_sample_)
{
m_timestamp_sample_ = _timestamp_sample_;
}

/*!
 * @brief This function returns the value of member timestamp_sample_
 * @return Value of member timestamp_sample_
 */
uint64_t estimator_attitude::timestamp_sample_() const
{
    return m_timestamp_sample_;
}

/*!
 * @brief This function returns a reference to member timestamp_sample_
 * @return Reference to member timestamp_sample_
 */
uint64_t& estimator_attitude::timestamp_sample_()
{
    return m_timestamp_sample_;
}

/*!
 * @brief This function copies the value in member q
 * @param _q New value to be copied in member q
 */
void estimator_attitude::q(const estimator_attitude__float_array_4 &_q)
{
m_q = _q;
}

/*!
 * @brief This function moves the value in member q
 * @param _q New value to be moved in member q
 */
void estimator_attitude::q(estimator_attitude__float_array_4 &&_q)
{
m_q = std::move(_q);
}

/*!
 * @brief This function returns a constant reference to member q
 * @return Constant reference to member q
 */
const estimator_attitude__float_array_4& estimator_attitude::q() const
{
    return m_q;
}

/*!
 * @brief This function returns a reference to member q
 * @return Reference to member q
 */
estimator_attitude__float_array_4& estimator_attitude::q()
{
    return m_q;
}
/*!
 * @brief This function copies the value in member delta_q_reset
 * @param _delta_q_reset New value to be copied in member delta_q_reset
 */
void estimator_attitude::delta_q_reset(const estimator_attitude__float_array_4 &_delta_q_reset)
{
m_delta_q_reset = _delta_q_reset;
}

/*!
 * @brief This function moves the value in member delta_q_reset
 * @param _delta_q_reset New value to be moved in member delta_q_reset
 */
void estimator_attitude::delta_q_reset(estimator_attitude__float_array_4 &&_delta_q_reset)
{
m_delta_q_reset = std::move(_delta_q_reset);
}

/*!
 * @brief This function returns a constant reference to member delta_q_reset
 * @return Constant reference to member delta_q_reset
 */
const estimator_attitude__float_array_4& estimator_attitude::delta_q_reset() const
{
    return m_delta_q_reset;
}

/*!
 * @brief This function returns a reference to member delta_q_reset
 * @return Reference to member delta_q_reset
 */
estimator_attitude__float_array_4& estimator_attitude::delta_q_reset()
{
    return m_delta_q_reset;
}
/*!
 * @brief This function sets a value in member quat_reset_counter_
 * @param _quat_reset_counter_ New value for member quat_reset_counter_
 */
void estimator_attitude::quat_reset_counter_(uint8_t _quat_reset_counter_)
{
m_quat_reset_counter_ = _quat_reset_counter_;
}

/*!
 * @brief This function returns the value of member quat_reset_counter_
 * @return Value of member quat_reset_counter_
 */
uint8_t estimator_attitude::quat_reset_counter_() const
{
    return m_quat_reset_counter_;
}

/*!
 * @brief This function returns a reference to member quat_reset_counter_
 * @return Reference to member quat_reset_counter_
 */
uint8_t& estimator_attitude::quat_reset_counter_()
{
    return m_quat_reset_counter_;
}


size_t estimator_attitude::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;








    return current_align;
}

bool estimator_attitude::isKeyDefined()
{
   return false;
}

void estimator_attitude::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
     
}
