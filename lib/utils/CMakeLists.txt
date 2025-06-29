# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/config.cmake)

# Project metadata
set(PROJECT_NAME utils)
project(${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "Utils library provides various utility functions, classes and constants.")
message(STATUS "Configuring project: ${PROJECT_NAME} v${PROJECT_VERSION}...")

# ----------------------------------- Interfaces ---------------------------------------
add_library(utils INTERFACE)
target_include_directories(utils
    INTERFACE
        include
)

# ---------------------------------- Confimation ---------------------------------------
message(NOTICE "Configured: ${PROJECT_NAME} v${PROJECT_VERSION}")