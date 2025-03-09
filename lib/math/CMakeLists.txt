# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/config.cmake)

# Project metadata
set(PROJECT_NAME math)
project(${PROJECT_NAME} VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
message(STATUS "Composing project: ${PROJECT_NAME} v${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Include utils
if(NOT TARGET algorithm_utils)
    add_subdirectory(../utils ${CMAKE_CURRENT_BINARY_DIR}/utils)
endif()

# Math Hasher
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
        algorithm_utils
)

# Math
add_library(algorithm_math
    INTERFACE
)
target_include_directories(algorithm_math
    INTERFACE
        include
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(algorithm_math
    INTERFACE
        math_hasher
)