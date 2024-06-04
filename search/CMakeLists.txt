# CMake version
cmake_minimum_required(VERSION 3.29)

# Project name
project(search)

# Global/Local settings
set_property(GLOBAL PROPERTY search_ADDED "ON")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include third party libraries
# Eigen
set(EIGEN3_INCLUDE_DIR ../third_party/eigen)
# Plog
if(NOT TARGET plog)
    add_subdirectory(../third_party/plog ${CMAKE_CURRENT_BINARY_DIR}/plog)
endif()

# Node
add_library(search_node SHARED
    src/node.cpp)
target_include_directories(search_node PUBLIC include ${EIGEN3_INCLUDE_DIR})
target_link_libraries(search_node PUBLIC plog)

# BASE SEARCH
add_library(search_base SHARED
    src/search/base.cpp)
target_include_directories(search_base PUBLIC include)
target_link_libraries(search_base PUBLIC plog search_node)

# BFS
add_library(search_bfs SHARED
    src/search/bfs.cpp)
target_include_directories(search_bfs PUBLIC include)
target_link_libraries(search_bfs PUBLIC plog search_node search_base)

# DFS
add_library(search_dfs SHARED
    src/search/dfs.cpp)
target_include_directories(search_dfs PUBLIC include)
target_link_libraries(search_dfs PUBLIC plog search_node search_base)

# UCS
add_library(search_ucs SHARED
    src/search/ucs.cpp)
target_include_directories(search_ucs PUBLIC include)
target_link_libraries(search_ucs PUBLIC plog search_node search_base)

# AStar
add_library(search_a_star SHARED
    src/search/a_star.cpp)
target_include_directories(search_a_star PUBLIC include)
target_link_libraries(search_a_star PUBLIC plog search_node search_base)

# Environment
add_library(search_environment SHARED
    src/environment.cpp)
target_include_directories(search_environment PUBLIC include)
target_link_libraries(search_environment PUBLIC plog search_node search_dfs search_bfs search_ucs search_a_star)