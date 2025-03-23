# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/config.cmake)

# Project metadata
set(PROJECT_NAME math)
project(${PROJECT_NAME} 
    VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
    DESCRIPTION "Math library with support for linear algebra, statistics, geometry, calculus, and more.")
message(STATUS "Configuring project: ${PROJECT_NAME} v${PROJECT_VERSION}")

# Find required packages
find_package(Boost REQUIRED)

# Include utils library
if (NOT TARGET utils)
    add_subdirectory(../utils ${CMAKE_CURRENT_BINARY_DIR}/utils)
endif()

# Math hasher
add_library(math_hasher
    SHARED
        src/hasher.cpp
)
target_include_directories(math_hasher
    PRIVATE
        include
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(math_hasher
    PRIVATE
        utils
)

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
        math_hasher
)