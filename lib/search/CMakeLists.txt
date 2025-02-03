# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/config.cmake)

# Project metadata
set(PROJECT_NAME search)
project(${PROJECT_NAME} VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
message(STATUS "Composing project: ${PROJECT_NAME} v${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Include third party libraries
# Eigen
set(EIGEN3_INCLUDE_DIR ../../third_party/eigen)

# Node
add_library(search_node
    SHARED
        src/node.cpp
)
target_include_directories(search_node
    PUBLIC
        include
        ${EIGEN3_INCLUDE_DIR}
)

# BASE SEARCH
add_library(search_base
    SHARED
        src/search/base.cpp
)
target_include_directories(search_base
    PUBLIC
        include
)
target_link_libraries(search_base
    PUBLIC
        search_node
)

# BFS
add_library(search_bfs
    SHARED
        src/search/bfs.cpp
)
target_include_directories(search_bfs
    PUBLIC
        include
)
target_link_libraries(search_bfs
    PUBLIC
        search_base
)

# DFS
add_library(search_dfs
    SHARED
        src/search/dfs.cpp
)
target_include_directories(search_dfs
    PUBLIC
        include
)
target_link_libraries(search_dfs
    PUBLIC
        search_base
)

# UCS
add_library(search_ucs
    SHARED
        src/search/ucs.cpp
)
target_include_directories(search_ucs
    PUBLIC
        include
)
target_link_libraries(search_ucs
    PUBLIC
        search_base
)

# AStar
add_library(search_a_star
    SHARED
        src/search/a_star.cpp
)
target_include_directories(search_a_star
    PUBLIC
        include
)
target_link_libraries(search_a_star
    PUBLIC
        search_base
)

# Environment
add_library(search_environment
    SHARED
        src/environment.cpp
)
target_include_directories(search_environment
    PUBLIC
        include
)
target_link_libraries(search_environment
    PUBLIC
        search_dfs
        search_bfs
        search_ucs
        search_a_star
)