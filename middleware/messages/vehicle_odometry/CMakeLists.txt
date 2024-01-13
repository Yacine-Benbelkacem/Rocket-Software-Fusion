cmake_minimum_required(VERSION 3.16.3)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

get_filename_component(MSG_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}  NAME)



project(${MSG_PREFIX})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "Configuring ${MSG_PREFIX}...")

add_library(${MSG_PREFIX}_lib ${MSG_PREFIX}PubSubTypes.cxx ${MSG_PREFIX}.cxx)
target_link_libraries(${MSG_PREFIX}_lib fastcdr fastrtps)

install(TARGETS ${MSG_PREFIX}_lib  DESTINATION $ENV{fusion_messages_libs_install})
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${HEADER_FILES} DESTINATION  $ENV{fusion_messages_includes_install}/${MSG_PREFIX})


