# CMake version
cmake_minimum_required(VERSION 3.29)

# Project name
project(search)

# Global/Local settings
set_property(GLOBAL PROPERTY search_ADDED "ON")
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include third party libraries
set (EIGEN3_INCLUDE_DIR ../third_party/eigen)
if (NOT TARGET plog)
    add_subdirectory(../third_party/plog ${CMAKE_CURRENT_BINARY_DIR}/plog)
endif()

# Node
add_library(search_node SHARED
    src/node.cpp)
target_include_directories(search_node PUBLIC include ${EIGEN3_INCLUDE_DIR})
target_link_libraries(search_node PUBLIC plog)

# Environment
add_library(search_environment SHARED
    src/environment.cpp)
target_include_directories(search_environment PUBLIC include ${EIGEN3_INCLUDE_DIR})
target_link_libraries(search_environment PUBLIC plog search_node)

# __main__
add_executable(search_main __main__.cpp)
target_link_libraries(search_main PRIVATE search_node search_environment)
target_compile_definitions(search_main PRIVATE FLOATING_POINT_TYPE=double DIM=1U)