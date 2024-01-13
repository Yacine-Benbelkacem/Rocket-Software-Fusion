cmake_minimum_required(VERSION 3.16.2)
set(PROJECT_NAME  rocket_fsm)
project(${PROJECT_NAME})

set(TARGET_NAME fsm)

#set(ENV{CMAKE_TOOLCHAIN_FILE} "/home/yacine/FastDDS/qnx.nto.toolchain.cmake")

set(CMAKE_CXX_FLAGS "$ENV{CFLAGS}  ${CMAKE_CXX_FLAGS} ")

set(SRCS src)

find_package(Threads REQUIRED)
find_package(fastrtps)

include_directories(
     $ENV{qnxexternal}/middleware/
     $ENV{qnxexternal}/middleware/messages/vehicle_command
     $ENV{qnxexternal}/middleware/publisher
     $ENV{qnxexternal}/middleware/subscriber
     tinyfsm/include
     src
 )

link_directories(
     $ENV{qnxexternal}/install/lib/messages
     $ENV{qnxexternal}/install/lib/publisher
     $ENV{qnxexternal}/install/lib/subscriber
     $ENV{qnxexternal}/install/lib
)


set(PROJECT_LINK_LIBS 
    publisher_s_lib
    subscriber_s_lib
    vehicle_command_lib
    vehicle_local_position_lib
    fsmDataOut_lib
    fastrtps
)


#add_subdirectory(middleware)

add_executable(${TARGET_NAME} ${SRCS}/main.cpp)
target_link_libraries(${TARGET_NAME}  ${PROJECT_LINK_LIBS} ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS ${TARGET_NAME} DESTINATION $ENV{fusion_bin_install})


