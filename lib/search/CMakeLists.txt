# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/config.cmake)

# Project metadata
set(PROJECT_NAME search)
project(${PROJECT_NAME} VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
    DESCRIPTION "Search library enables efficient searching using various algorithms in a defined space.")
message(STATUS "Configuring project: ${PROJECT_NAME} v${PROJECT_VERSION}")

# Include third party libraries
if (NOT TARGET plog)
    add_subdirectory(../../third_party/plog ${CMAKE_CURRENT_BINARY_DIR}/plog)
endif()

# Include utils library
if (NOT TARGET utils)
    add_subdirectory(../utils ${CMAKE_CURRENT_BINARY_DIR}/utils)
endif()

# Include utils library
if (NOT TARGET math)
    add_subdirectory(../math ${CMAKE_CURRENT_BINARY_DIR}/math)
endif()

# ---------------------------------- Node ---------------------------------------
# Search - Node
add_library(search_node
    SHARED
        src/node/node.cpp
)
target_include_directories(search_node
    PRIVATE
        include
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(search_node
    PRIVATE
        math
        plog
)

# ---------------------------------- Cost ---------------------------------------
# Search - DefaultCost
add_library(search_default_cost
    SHARED
        src/cost/default_cost.cpp
)
target_include_directories(search_default_cost
    PRIVATE
        include
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(search_default_cost
    PRIVATE
        utils
        math
        plog
)

# Search - DistanceCost
add_library(search_distance_cost
    SHARED
        src/cost/distance_cost.cpp
)
target_include_directories(search_distance_cost
    PRIVATE
        include
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(search_distance_cost
    PRIVATE
        utils
        math
        plog
)

# Search - AggregateCost
add_library(search_aggregate_cost
    SHARED
        src/cost/aggregate_cost.cpp
)
target_include_directories(search_aggregate_cost
    PRIVATE
        include
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(search_aggregate_cost
    PRIVATE
        utils
        math
        plog
)

# ---------------------------------- Environment ---------------------------------------
# Search - Graph based environment
add_library(search_graph_environment
    SHARED
        src/environment/graph.cpp
)
target_include_directories(search_graph_environment
    PRIVATE
        include
        ${EIGEN3_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(search_graph_environment
    PRIVATE
        math
        utils
        plog
        search_node
        search_default_cost
        search_distance_cost
        search_aggregate_cost
)