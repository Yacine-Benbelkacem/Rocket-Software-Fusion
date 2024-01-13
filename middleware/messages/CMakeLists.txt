cmake_minimum_required(VERSION 3.16.2)

#set(ENV{CMAKE_TOOLCHAIN_FILE} "/home/yacine/FastDDS/qnx.nto.toolchain.cmake")


add_subdirectory(fsmDataOut)
add_subdirectory(vehicle_command)
add_subdirectory(vehicle_local_position)
add_subdirectory(vehicle_local_position_groundtruth)
add_subdirectory(actuator_controls_0)
add_subdirectory(vehicle_attitude)
add_subdirectory(vehicle_attitude_groundtruth)
add_subdirectory(vehicle_angular_velocity)
add_subdirectory(vehicle_angular_velocity_groundtruth)
add_subdirectory(actuator_controls)
add_subdirectory(vehicle_visual_odometry)
add_subdirectory(vehicle_odometry)
add_subdirectory(timesync)
