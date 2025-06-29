# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/config.cmake)

# Project metadata
set(PROJECT_NAME math)
project(${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "Math library with support for linear algebra, statistics, geometry, calculus, and more.")
message(STATUS "Configuring project: ${PROJECT_NAME} v${PROJECT_VERSION}...")

# Include third-party libraries
# Custom libraries
if (NOT TARGET utils)
    add_subdirectory(../utils ${CMAKE_CURRENT_BINARY_DIR}/utils)
endif()

# Open-sourced libraries
find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)

# ---------------------------------- Interfaces ---------------------------------------
# Math
add_library(math
    INTERFACE
)
target_include_directories(math
    INTERFACE
        include
)
target_link_libraries(math
    INTERFACE
        utils
        Eigen3::Eigen
        Boost::boost
)

# ---------------------------------- Confimation ---------------------------------------
message(NOTICE "Configured: ${PROJECT_NAME} v${PROJECT_VERSION}")