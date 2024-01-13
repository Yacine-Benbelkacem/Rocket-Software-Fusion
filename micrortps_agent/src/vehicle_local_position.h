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
 * @file vehicle_local_position.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _VEHICLE_LOCAL_POSITION_H_
#define _VEHICLE_LOCAL_POSITION_H_

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
#if defined(vehicle_local_position_SOURCE)
#define vehicle_local_position_DllAPI __declspec( dllexport )
#else
#define vehicle_local_position_DllAPI __declspec( dllimport )
#endif // vehicle_local_position_SOURCE
#else
#define vehicle_local_position_DllAPI
#endif
#else
#define vehicle_local_position_DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


const uint8_t vehicle_local_position__DIST_BOTTOM_SENSOR_NONE = 0;
const uint8_t vehicle_local_position__DIST_BOTTOM_SENSOR_RANGE = 1;
const uint8_t vehicle_local_position__DIST_BOTTOM_SENSOR_FLOW = 2;
typedef std::array<float, 2> vehicle_local_position__float_array_2;
/*!
 * @brief This class represents the structure vehicle_local_position defined by the user in the IDL file.
 * @ingroup VEHICLE_LOCAL_POSITION
 */
class vehicle_local_position
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport vehicle_local_position();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~vehicle_local_position();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object vehicle_local_position that will be copied.
     */
    eProsima_user_DllExport vehicle_local_position(const vehicle_local_position &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object vehicle_local_position that will be copied.
     */
    eProsima_user_DllExport vehicle_local_position(vehicle_local_position &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object vehicle_local_position that will be copied.
     */
    eProsima_user_DllExport vehicle_local_position& operator=(const vehicle_local_position &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object vehicle_local_position that will be copied.
     */
    eProsima_user_DllExport vehicle_local_position& operator=(vehicle_local_position &&x);

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
     * @brief This function sets a value in member xy_valid_
     * @param _xy_valid_ New value for member xy_valid_
     */
    eProsima_user_DllExport void xy_valid_(bool _xy_valid_);

    /*!
     * @brief This function returns the value of member xy_valid_
     * @return Value of member xy_valid_
     */
    eProsima_user_DllExport bool xy_valid_() const;

    /*!
     * @brief This function returns a reference to member xy_valid_
     * @return Reference to member xy_valid_
     */
    eProsima_user_DllExport bool& xy_valid_();

    /*!
     * @brief This function sets a value in member z_valid_
     * @param _z_valid_ New value for member z_valid_
     */
    eProsima_user_DllExport void z_valid_(bool _z_valid_);

    /*!
     * @brief This function returns the value of member z_valid_
     * @return Value of member z_valid_
     */
    eProsima_user_DllExport bool z_valid_() const;

    /*!
     * @brief This function returns a reference to member z_valid_
     * @return Reference to member z_valid_
     */
    eProsima_user_DllExport bool& z_valid_();

    /*!
     * @brief This function sets a value in member v_xy_valid_
     * @param _v_xy_valid_ New value for member v_xy_valid_
     */
    eProsima_user_DllExport void v_xy_valid_(bool _v_xy_valid_);

    /*!
     * @brief This function returns the value of member v_xy_valid_
     * @return Value of member v_xy_valid_
     */
    eProsima_user_DllExport bool v_xy_valid_() const;

    /*!
     * @brief This function returns a reference to member v_xy_valid_
     * @return Reference to member v_xy_valid_
     */
    eProsima_user_DllExport bool& v_xy_valid_();

    /*!
     * @brief This function sets a value in member v_z_valid_
     * @param _v_z_valid_ New value for member v_z_valid_
     */
    eProsima_user_DllExport void v_z_valid_(bool _v_z_valid_);

    /*!
     * @brief This function returns the value of member v_z_valid_
     * @return Value of member v_z_valid_
     */
    eProsima_user_DllExport bool v_z_valid_() const;

    /*!
     * @brief This function returns a reference to member v_z_valid_
     * @return Reference to member v_z_valid_
     */
    eProsima_user_DllExport bool& v_z_valid_();

    /*!
     * @brief This function sets a value in member x_
     * @param _x_ New value for member x_
     */
    eProsima_user_DllExport void x_(float _x_);

    /*!
     * @brief This function returns the value of member x_
     * @return Value of member x_
     */
    eProsima_user_DllExport float x_() const;

    /*!
     * @brief This function returns a reference to member x_
     * @return Reference to member x_
     */
    eProsima_user_DllExport float& x_();

    /*!
     * @brief This function sets a value in member y_
     * @param _y_ New value for member y_
     */
    eProsima_user_DllExport void y_(float _y_);

    /*!
     * @brief This function returns the value of member y_
     * @return Value of member y_
     */
    eProsima_user_DllExport float y_() const;

    /*!
     * @brief This function returns a reference to member y_
     * @return Reference to member y_
     */
    eProsima_user_DllExport float& y_();

    /*!
     * @brief This function sets a value in member z_
     * @param _z_ New value for member z_
     */
    eProsima_user_DllExport void z_(float _z_);

    /*!
     * @brief This function returns the value of member z_
     * @return Value of member z_
     */
    eProsima_user_DllExport float z_() const;

    /*!
     * @brief This function returns a reference to member z_
     * @return Reference to member z_
     */
    eProsima_user_DllExport float& z_();

    /*!
     * @brief This function copies the value in member delta_xy
     * @param _delta_xy New value to be copied in member delta_xy
     */
    eProsima_user_DllExport void delta_xy(const vehicle_local_position__float_array_2 &_delta_xy);

    /*!
     * @brief This function moves the value in member delta_xy
     * @param _delta_xy New value to be moved in member delta_xy
     */
    eProsima_user_DllExport void delta_xy(vehicle_local_position__float_array_2 &&_delta_xy);

    /*!
     * @brief This function returns a constant reference to member delta_xy
     * @return Constant reference to member delta_xy
     */
    eProsima_user_DllExport const vehicle_local_position__float_array_2& delta_xy() const;

    /*!
     * @brief This function returns a reference to member delta_xy
     * @return Reference to member delta_xy
     */
    eProsima_user_DllExport vehicle_local_position__float_array_2& delta_xy();
    /*!
     * @brief This function sets a value in member xy_reset_counter_
     * @param _xy_reset_counter_ New value for member xy_reset_counter_
     */
    eProsima_user_DllExport void xy_reset_counter_(uint8_t _xy_reset_counter_);

    /*!
     * @brief This function returns the value of member xy_reset_counter_
     * @return Value of member xy_reset_counter_
     */
    eProsima_user_DllExport uint8_t xy_reset_counter_() const;

    /*!
     * @brief This function returns a reference to member xy_reset_counter_
     * @return Reference to member xy_reset_counter_
     */
    eProsima_user_DllExport uint8_t& xy_reset_counter_();

    /*!
     * @brief This function sets a value in member delta_z_
     * @param _delta_z_ New value for member delta_z_
     */
    eProsima_user_DllExport void delta_z_(float _delta_z_);

    /*!
     * @brief This function returns the value of member delta_z_
     * @return Value of member delta_z_
     */
    eProsima_user_DllExport float delta_z_() const;

    /*!
     * @brief This function returns a reference to member delta_z_
     * @return Reference to member delta_z_
     */
    eProsima_user_DllExport float& delta_z_();

    /*!
     * @brief This function sets a value in member z_reset_counter_
     * @param _z_reset_counter_ New value for member z_reset_counter_
     */
    eProsima_user_DllExport void z_reset_counter_(uint8_t _z_reset_counter_);

    /*!
     * @brief This function returns the value of member z_reset_counter_
     * @return Value of member z_reset_counter_
     */
    eProsima_user_DllExport uint8_t z_reset_counter_() const;

    /*!
     * @brief This function returns a reference to member z_reset_counter_
     * @return Reference to member z_reset_counter_
     */
    eProsima_user_DllExport uint8_t& z_reset_counter_();

    /*!
     * @brief This function sets a value in member vx_
     * @param _vx_ New value for member vx_
     */
    eProsima_user_DllExport void vx_(float _vx_);

    /*!
     * @brief This function returns the value of member vx_
     * @return Value of member vx_
     */
    eProsima_user_DllExport float vx_() const;

    /*!
     * @brief This function returns a reference to member vx_
     * @return Reference to member vx_
     */
    eProsima_user_DllExport float& vx_();

    /*!
     * @brief This function sets a value in member vy_
     * @param _vy_ New value for member vy_
     */
    eProsima_user_DllExport void vy_(float _vy_);

    /*!
     * @brief This function returns the value of member vy_
     * @return Value of member vy_
     */
    eProsima_user_DllExport float vy_() const;

    /*!
     * @brief This function returns a reference to member vy_
     * @return Reference to member vy_
     */
    eProsima_user_DllExport float& vy_();

    /*!
     * @brief This function sets a value in member vz_
     * @param _vz_ New value for member vz_
     */
    eProsima_user_DllExport void vz_(float _vz_);

    /*!
     * @brief This function returns the value of member vz_
     * @return Value of member vz_
     */
    eProsima_user_DllExport float vz_() const;

    /*!
     * @brief This function returns a reference to member vz_
     * @return Reference to member vz_
     */
    eProsima_user_DllExport float& vz_();

    /*!
     * @brief This function sets a value in member z_deriv_
     * @param _z_deriv_ New value for member z_deriv_
     */
    eProsima_user_DllExport void z_deriv_(float _z_deriv_);

    /*!
     * @brief This function returns the value of member z_deriv_
     * @return Value of member z_deriv_
     */
    eProsima_user_DllExport float z_deriv_() const;

    /*!
     * @brief This function returns a reference to member z_deriv_
     * @return Reference to member z_deriv_
     */
    eProsima_user_DllExport float& z_deriv_();

    /*!
     * @brief This function copies the value in member delta_vxy
     * @param _delta_vxy New value to be copied in member delta_vxy
     */
    eProsima_user_DllExport void delta_vxy(const vehicle_local_position__float_array_2 &_delta_vxy);

    /*!
     * @brief This function moves the value in member delta_vxy
     * @param _delta_vxy New value to be moved in member delta_vxy
     */
    eProsima_user_DllExport void delta_vxy(vehicle_local_position__float_array_2 &&_delta_vxy);

    /*!
     * @brief This function returns a constant reference to member delta_vxy
     * @return Constant reference to member delta_vxy
     */
    eProsima_user_DllExport const vehicle_local_position__float_array_2& delta_vxy() const;

    /*!
     * @brief This function returns a reference to member delta_vxy
     * @return Reference to member delta_vxy
     */
    eProsima_user_DllExport vehicle_local_position__float_array_2& delta_vxy();
    /*!
     * @brief This function sets a value in member vxy_reset_counter_
     * @param _vxy_reset_counter_ New value for member vxy_reset_counter_
     */
    eProsima_user_DllExport void vxy_reset_counter_(uint8_t _vxy_reset_counter_);

    /*!
     * @brief This function returns the value of member vxy_reset_counter_
     * @return Value of member vxy_reset_counter_
     */
    eProsima_user_DllExport uint8_t vxy_reset_counter_() const;

    /*!
     * @brief This function returns a reference to member vxy_reset_counter_
     * @return Reference to member vxy_reset_counter_
     */
    eProsima_user_DllExport uint8_t& vxy_reset_counter_();

    /*!
     * @brief This function sets a value in member delta_vz_
     * @param _delta_vz_ New value for member delta_vz_
     */
    eProsima_user_DllExport void delta_vz_(float _delta_vz_);

    /*!
     * @brief This function returns the value of member delta_vz_
     * @return Value of member delta_vz_
     */
    eProsima_user_DllExport float delta_vz_() const;

    /*!
     * @brief This function returns a reference to member delta_vz_
     * @return Reference to member delta_vz_
     */
    eProsima_user_DllExport float& delta_vz_();

    /*!
     * @brief This function sets a value in member vz_reset_counter_
     * @param _vz_reset_counter_ New value for member vz_reset_counter_
     */
    eProsima_user_DllExport void vz_reset_counter_(uint8_t _vz_reset_counter_);

    /*!
     * @brief This function returns the value of member vz_reset_counter_
     * @return Value of member vz_reset_counter_
     */
    eProsima_user_DllExport uint8_t vz_reset_counter_() const;

    /*!
     * @brief This function returns a reference to member vz_reset_counter_
     * @return Reference to member vz_reset_counter_
     */
    eProsima_user_DllExport uint8_t& vz_reset_counter_();

    /*!
     * @brief This function sets a value in member ax_
     * @param _ax_ New value for member ax_
     */
    eProsima_user_DllExport void ax_(float _ax_);

    /*!
     * @brief This function returns the value of member ax_
     * @return Value of member ax_
     */
    eProsima_user_DllExport float ax_() const;

    /*!
     * @brief This function returns a reference to member ax_
     * @return Reference to member ax_
     */
    eProsima_user_DllExport float& ax_();

    /*!
     * @brief This function sets a value in member ay_
     * @param _ay_ New value for member ay_
     */
    eProsima_user_DllExport void ay_(float _ay_);

    /*!
     * @brief This function returns the value of member ay_
     * @return Value of member ay_
     */
    eProsima_user_DllExport float ay_() const;

    /*!
     * @brief This function returns a reference to member ay_
     * @return Reference to member ay_
     */
    eProsima_user_DllExport float& ay_();

    /*!
     * @brief This function sets a value in member az_
     * @param _az_ New value for member az_
     */
    eProsima_user_DllExport void az_(float _az_);

    /*!
     * @brief This function returns the value of member az_
     * @return Value of member az_
     */
    eProsima_user_DllExport float az_() const;

    /*!
     * @brief This function returns a reference to member az_
     * @return Reference to member az_
     */
    eProsima_user_DllExport float& az_();

    /*!
     * @brief This function sets a value in member heading_
     * @param _heading_ New value for member heading_
     */
    eProsima_user_DllExport void heading_(float _heading_);

    /*!
     * @brief This function returns the value of member heading_
     * @return Value of member heading_
     */
    eProsima_user_DllExport float heading_() const;

    /*!
     * @brief This function returns a reference to member heading_
     * @return Reference to member heading_
     */
    eProsima_user_DllExport float& heading_();

    /*!
     * @brief This function sets a value in member delta_heading_
     * @param _delta_heading_ New value for member delta_heading_
     */
    eProsima_user_DllExport void delta_heading_(float _delta_heading_);

    /*!
     * @brief This function returns the value of member delta_heading_
     * @return Value of member delta_heading_
     */
    eProsima_user_DllExport float delta_heading_() const;

    /*!
     * @brief This function returns a reference to member delta_heading_
     * @return Reference to member delta_heading_
     */
    eProsima_user_DllExport float& delta_heading_();

    /*!
     * @brief This function sets a value in member heading_reset_counter_
     * @param _heading_reset_counter_ New value for member heading_reset_counter_
     */
    eProsima_user_DllExport void heading_reset_counter_(uint8_t _heading_reset_counter_);

    /*!
     * @brief This function returns the value of member heading_reset_counter_
     * @return Value of member heading_reset_counter_
     */
    eProsima_user_DllExport uint8_t heading_reset_counter_() const;

    /*!
     * @brief This function returns a reference to member heading_reset_counter_
     * @return Reference to member heading_reset_counter_
     */
    eProsima_user_DllExport uint8_t& heading_reset_counter_();

    /*!
     * @brief This function sets a value in member xy_global_
     * @param _xy_global_ New value for member xy_global_
     */
    eProsima_user_DllExport void xy_global_(bool _xy_global_);

    /*!
     * @brief This function returns the value of member xy_global_
     * @return Value of member xy_global_
     */
    eProsima_user_DllExport bool xy_global_() const;

    /*!
     * @brief This function returns a reference to member xy_global_
     * @return Reference to member xy_global_
     */
    eProsima_user_DllExport bool& xy_global_();

    /*!
     * @brief This function sets a value in member z_global_
     * @param _z_global_ New value for member z_global_
     */
    eProsima_user_DllExport void z_global_(bool _z_global_);

    /*!
     * @brief This function returns the value of member z_global_
     * @return Value of member z_global_
     */
    eProsima_user_DllExport bool z_global_() const;

    /*!
     * @brief This function returns a reference to member z_global_
     * @return Reference to member z_global_
     */
    eProsima_user_DllExport bool& z_global_();

    /*!
     * @brief This function sets a value in member ref_timestamp_
     * @param _ref_timestamp_ New value for member ref_timestamp_
     */
    eProsima_user_DllExport void ref_timestamp_(uint64_t _ref_timestamp_);

    /*!
     * @brief This function returns the value of member ref_timestamp_
     * @return Value of member ref_timestamp_
     */
    eProsima_user_DllExport uint64_t ref_timestamp_() const;

    /*!
     * @brief This function returns a reference to member ref_timestamp_
     * @return Reference to member ref_timestamp_
     */
    eProsima_user_DllExport uint64_t& ref_timestamp_();

    /*!
     * @brief This function sets a value in member ref_lat_
     * @param _ref_lat_ New value for member ref_lat_
     */
    eProsima_user_DllExport void ref_lat_(double _ref_lat_);

    /*!
     * @brief This function returns the value of member ref_lat_
     * @return Value of member ref_lat_
     */
    eProsima_user_DllExport double ref_lat_() const;

    /*!
     * @brief This function returns a reference to member ref_lat_
     * @return Reference to member ref_lat_
     */
    eProsima_user_DllExport double& ref_lat_();

    /*!
     * @brief This function sets a value in member ref_lon_
     * @param _ref_lon_ New value for member ref_lon_
     */
    eProsima_user_DllExport void ref_lon_(double _ref_lon_);

    /*!
     * @brief This function returns the value of member ref_lon_
     * @return Value of member ref_lon_
     */
    eProsima_user_DllExport double ref_lon_() const;

    /*!
     * @brief This function returns a reference to member ref_lon_
     * @return Reference to member ref_lon_
     */
    eProsima_user_DllExport double& ref_lon_();

    /*!
     * @brief This function sets a value in member ref_alt_
     * @param _ref_alt_ New value for member ref_alt_
     */
    eProsima_user_DllExport void ref_alt_(float _ref_alt_);

    /*!
     * @brief This function returns the value of member ref_alt_
     * @return Value of member ref_alt_
     */
    eProsima_user_DllExport float ref_alt_() const;

    /*!
     * @brief This function returns a reference to member ref_alt_
     * @return Reference to member ref_alt_
     */
    eProsima_user_DllExport float& ref_alt_();

    /*!
     * @brief This function sets a value in member dist_bottom_
     * @param _dist_bottom_ New value for member dist_bottom_
     */
    eProsima_user_DllExport void dist_bottom_(float _dist_bottom_);

    /*!
     * @brief This function returns the value of member dist_bottom_
     * @return Value of member dist_bottom_
     */
    eProsima_user_DllExport float dist_bottom_() const;

    /*!
     * @brief This function returns a reference to member dist_bottom_
     * @return Reference to member dist_bottom_
     */
    eProsima_user_DllExport float& dist_bottom_();

    /*!
     * @brief This function sets a value in member dist_bottom_valid_
     * @param _dist_bottom_valid_ New value for member dist_bottom_valid_
     */
    eProsima_user_DllExport void dist_bottom_valid_(bool _dist_bottom_valid_);

    /*!
     * @brief This function returns the value of member dist_bottom_valid_
     * @return Value of member dist_bottom_valid_
     */
    eProsima_user_DllExport bool dist_bottom_valid_() const;

    /*!
     * @brief This function returns a reference to member dist_bottom_valid_
     * @return Reference to member dist_bottom_valid_
     */
    eProsima_user_DllExport bool& dist_bottom_valid_();

    /*!
     * @brief This function sets a value in member dist_bottom_sensor_bitfield_
     * @param _dist_bottom_sensor_bitfield_ New value for member dist_bottom_sensor_bitfield_
     */
    eProsima_user_DllExport void dist_bottom_sensor_bitfield_(uint8_t _dist_bottom_sensor_bitfield_);

    /*!
     * @brief This function returns the value of member dist_bottom_sensor_bitfield_
     * @return Value of member dist_bottom_sensor_bitfield_
     */
    eProsima_user_DllExport uint8_t dist_bottom_sensor_bitfield_() const;

    /*!
     * @brief This function returns a reference to member dist_bottom_sensor_bitfield_
     * @return Reference to member dist_bottom_sensor_bitfield_
     */
    eProsima_user_DllExport uint8_t& dist_bottom_sensor_bitfield_();

    /*!
     * @brief This function sets a value in member eph_
     * @param _eph_ New value for member eph_
     */
    eProsima_user_DllExport void eph_(float _eph_);

    /*!
     * @brief This function returns the value of member eph_
     * @return Value of member eph_
     */
    eProsima_user_DllExport float eph_() const;

    /*!
     * @brief This function returns a reference to member eph_
     * @return Reference to member eph_
     */
    eProsima_user_DllExport float& eph_();

    /*!
     * @brief This function sets a value in member epv_
     * @param _epv_ New value for member epv_
     */
    eProsima_user_DllExport void epv_(float _epv_);

    /*!
     * @brief This function returns the value of member epv_
     * @return Value of member epv_
     */
    eProsima_user_DllExport float epv_() const;

    /*!
     * @brief This function returns a reference to member epv_
     * @return Reference to member epv_
     */
    eProsima_user_DllExport float& epv_();

    /*!
     * @brief This function sets a value in member evh_
     * @param _evh_ New value for member evh_
     */
    eProsima_user_DllExport void evh_(float _evh_);

    /*!
     * @brief This function returns the value of member evh_
     * @return Value of member evh_
     */
    eProsima_user_DllExport float evh_() const;

    /*!
     * @brief This function returns a reference to member evh_
     * @return Reference to member evh_
     */
    eProsima_user_DllExport float& evh_();

    /*!
     * @brief This function sets a value in member evv_
     * @param _evv_ New value for member evv_
     */
    eProsima_user_DllExport void evv_(float _evv_);

    /*!
     * @brief This function returns the value of member evv_
     * @return Value of member evv_
     */
    eProsima_user_DllExport float evv_() const;

    /*!
     * @brief This function returns a reference to member evv_
     * @return Reference to member evv_
     */
    eProsima_user_DllExport float& evv_();

    /*!
     * @brief This function sets a value in member vxy_max_
     * @param _vxy_max_ New value for member vxy_max_
     */
    eProsima_user_DllExport void vxy_max_(float _vxy_max_);

    /*!
     * @brief This function returns the value of member vxy_max_
     * @return Value of member vxy_max_
     */
    eProsima_user_DllExport float vxy_max_() const;

    /*!
     * @brief This function returns a reference to member vxy_max_
     * @return Reference to member vxy_max_
     */
    eProsima_user_DllExport float& vxy_max_();

    /*!
     * @brief This function sets a value in member vz_max_
     * @param _vz_max_ New value for member vz_max_
     */
    eProsima_user_DllExport void vz_max_(float _vz_max_);

    /*!
     * @brief This function returns the value of member vz_max_
     * @return Value of member vz_max_
     */
    eProsima_user_DllExport float vz_max_() const;

    /*!
     * @brief This function returns a reference to member vz_max_
     * @return Reference to member vz_max_
     */
    eProsima_user_DllExport float& vz_max_();

    /*!
     * @brief This function sets a value in member hagl_min_
     * @param _hagl_min_ New value for member hagl_min_
     */
    eProsima_user_DllExport void hagl_min_(float _hagl_min_);

    /*!
     * @brief This function returns the value of member hagl_min_
     * @return Value of member hagl_min_
     */
    eProsima_user_DllExport float hagl_min_() const;

    /*!
     * @brief This function returns a reference to member hagl_min_
     * @return Reference to member hagl_min_
     */
    eProsima_user_DllExport float& hagl_min_();

    /*!
     * @brief This function sets a value in member hagl_max_
     * @param _hagl_max_ New value for member hagl_max_
     */
    eProsima_user_DllExport void hagl_max_(float _hagl_max_);

    /*!
     * @brief This function returns the value of member hagl_max_
     * @return Value of member hagl_max_
     */
    eProsima_user_DllExport float hagl_max_() const;

    /*!
     * @brief This function returns a reference to member hagl_max_
     * @return Reference to member hagl_max_
     */
    eProsima_user_DllExport float& hagl_max_();


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
    eProsima_user_DllExport static size_t getCdrSerializedSize(const vehicle_local_position& data, size_t current_alignment = 0);


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
    bool m_xy_valid_;
    bool m_z_valid_;
    bool m_v_xy_valid_;
    bool m_v_z_valid_;
    float m_x_;
    float m_y_;
    float m_z_;
    vehicle_local_position__float_array_2 m_delta_xy;
    uint8_t m_xy_reset_counter_;
    float m_delta_z_;
    uint8_t m_z_reset_counter_;
    float m_vx_;
    float m_vy_;
    float m_vz_;
    float m_z_deriv_;
    vehicle_local_position__float_array_2 m_delta_vxy;
    uint8_t m_vxy_reset_counter_;
    float m_delta_vz_;
    uint8_t m_vz_reset_counter_;
    float m_ax_;
    float m_ay_;
    float m_az_;
    float m_heading_;
    float m_delta_heading_;
    uint8_t m_heading_reset_counter_;
    bool m_xy_global_;
    bool m_z_global_;
    uint64_t m_ref_timestamp_;
    double m_ref_lat_;
    double m_ref_lon_;
    float m_ref_alt_;
    float m_dist_bottom_;
    bool m_dist_bottom_valid_;
    uint8_t m_dist_bottom_sensor_bitfield_;
    float m_eph_;
    float m_epv_;
    float m_evh_;
    float m_evv_;
    float m_vxy_max_;
    float m_vz_max_;
    float m_hagl_min_;
    float m_hagl_max_;
};

#endif // _VEHICLE_LOCAL_POSITION_H_