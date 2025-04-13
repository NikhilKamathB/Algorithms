# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/config.cmake)

# Project metadata
set(PROJECT_NAME utils)
project(${PROJECT_NAME} 
    VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
    DESCRIPTION "Utils library provides various utility functions, classes and constants.")
message(STATUS "Configuring project: ${PROJECT_NAME} v${PROJECT_VERSION}")

# ----------------------------------- Interfaces ---------------------------------------
add_library(utils INTERFACE)
target_include_directories(utils
    INTERFACE
        include
)