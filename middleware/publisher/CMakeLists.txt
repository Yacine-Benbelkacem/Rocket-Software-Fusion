cmake_minimum_required(VERSION 2.8.12)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

get_filename_component(MODULE_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}  NAME)

project("${MODULE_PREFIX}_module")

set(TARGET_NAME ${MODULE_PREFIX}_s_lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)


message(STATUS "Configuring ${MODULE_PREFIX}_s...")

add_library(${TARGET_NAME} ${MODULE_PREFIX}_s.cxx)
target_link_libraries(${TARGET_NAME} fastcdr fastrtps)


install(TARGETS ${TARGET_NAME}  DESTINATION $ENV{fusion_libs_install})
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${HEADER_FILES} DESTINATION  $ENV{fusion_includes_install}/publisher)




