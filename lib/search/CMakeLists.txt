# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/config.cmake)

# Project metadata
set(PROJECT_NAME search)
project(${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "Search library enables efficient searching using various algorithms in a defined space.")
message(STATUS "Configuring project: ${PROJECT_NAME} v${PROJECT_VERSION}...")

option(BUILD_TEST_SEARCH "Build search test" ON)
set_property(GLOBAL PROPERTY BUILD_SEARCH_TEST ${BUILD_SEARCH_TEST})

# Include third party libraries
# Custom libraries
if (NOT TARGET utils)
    add_subdirectory(../utils ${CMAKE_CURRENT_BINARY_DIR}/utils)
endif()
if (NOT TARGET math)
    add_subdirectory(../math ${CMAKE_CURRENT_BINARY_DIR}/math)
endif()
# Open-sourced libraries
find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(plog REQUIRED)
if (BUILD_TEST_SEARCH)
    find_package(GTest REQUIRED)
endif()

# ---------------------------------- Interfaces ---------------------------------------
# Search
add_library(search
    INTERFACE
)
target_include_directories(search
    INTERFACE
        include
)
target_link_libraries(search
    INTERFACE
        utils
        math
        Eigen3::Eigen
        Boost::boost
        plog::plog
)

# ------------------------------------- Test ------------------------------------------
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TEST_SEARCH)
    message(STATUS "Building tests for ${PROJECT_NAME}...")
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

# ---------------------------------- Confimation ---------------------------------------
message(NOTICE "Configured: ${PROJECT_NAME} v${PROJECT_VERSION}")