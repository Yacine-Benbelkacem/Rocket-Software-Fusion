cmake_minimum_required(VERSION 3.16.2)
project(rocket_mpc)
set(TARGET_NAME mpc)

set(SOLVER acado)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

#set(CMAKE_CXX_FLAGS "$ENV{CFLAGS}  ${CMAKE_CXX_FLAGS} -lRocketSolver -L${qnxexternal}/control/RocketSolver/lib -O3 -finline-functions ")
set(CMAKE_CXX_FLAGS "$ENV{CFLAGS}  ${CMAKE_CXX_FLAGS} -O3 -finline-functions ")
set(CMAKE_C_FLAGS "$ENV{CFLAGS}  -O3 -finline-functions ")




find_package(Threads REQUIRED)

include_directories(
     ../middleware
     if(${SOLVER} equal forces)
        RocketSolver/include
        RocketSolver/interface
     endif()
     AcadoSolver
     AcadoSolver/qpoases
     AcadoSolver/qpoases/INCLUDE
     AcadoSolver/qpoases/SRC
     src

 )

link_directories(
     src
     $ENV{qnxexternal}/control/RocketSolver/lib
     $ENV{qnxexternal}/control/RocketSolver/interface
     $ENV{qnxexternal}/install/lib/publisher
     $ENV{qnxexternal}/install/lib/subscriber
     $ENV{qnxexternal}/install/lib/messages    
     $ENV{qnxexternal}/install/lib
)


# add the messages folders here both for the Structure and Type(topic)
set(PROJECT_LINK_LIBS 
    
    # PX4 data/topics libs
    fastrtps
    fastcdr
    
    publisher_s_lib
    subscriber_s_lib
    
    actuator_controls_0_lib
    actuator_controls_lib
    vehicle_command_lib
    vehicle_local_position_lib
    vehicle_local_position_groundtruth_lib
    vehicle_attitude_groundtruth_lib
    vehicle_angular_velocity_lib
    vehicle_angular_velocity_groundtruth_lib

    vehicle_odometry_lib

    fsmDataOut_lib

    # solver libs
    #RocketSolver    
    stdc++
    m
    )









set(SRCS src)

add_library(acadolibs
AcadoSolver/qpoases/SRC/Bounds.cpp
AcadoSolver/qpoases/SRC/Constraints.cpp
AcadoSolver/qpoases/SRC/CyclingManager.cpp
AcadoSolver/qpoases/SRC/Indexlist.cpp
AcadoSolver/qpoases/SRC/MessageHandling.cpp
AcadoSolver/qpoases/SRC/QProblem.cpp
AcadoSolver/qpoases/SRC/QProblemB.cpp
AcadoSolver/qpoases/SRC/SubjectTo.cpp
AcadoSolver/qpoases/SRC/Utils.cpp
AcadoSolver/qpoases/SRC/EXTRAS/SolutionAnalysis.cpp
AcadoSolver/acado_qpoases_interface.cpp
AcadoSolver/acado_integrator.c
AcadoSolver/acado_solver.c
AcadoSolver/acado_auxiliary_functions.c)


add_executable(${TARGET_NAME} 
               ${SRCS}/main.cxx
               ${SRCS}/mpc.cxx
                #./RocketSolver/interface/RocketSolver_adtool2forces.c
                #./RocketSolver/interface/RocketSolver_casadi.c
               )

target_link_libraries(${TARGET_NAME}
                      ${PROJECT_LINK_LIBS}
                      ${CMAKE_THREAD_LIBS_INIT}
                      acadolibs
                      )

install(TARGETS ${TARGET_NAME} DESTINATION $ENV{fusion_bin_install})




