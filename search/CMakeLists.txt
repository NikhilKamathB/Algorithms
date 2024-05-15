# CMake version
cmake_minimum_required(VERSION 3.29)

# Project name
project(search)

# Global/Local settings
set_property(GLOBAL PROPERTY search_ADDED "ON")
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include third party libraries
if (NOT TARGET eigen)
    add_subdirectory(../third_party/eigen ${CMAKE_CURRENT_BINARY_DIR}/eigen)
endif()
if (NOT TARGET plog)
    add_subdirectory(../third_party/plog ${CMAKE_CURRENT_BINARY_DIR}/plog)
endif()

# Node
add_library(search_node SHARED
    src/node.cpp)
target_include_directories(search_node PUBLIC include)
target_link_libraries(search_node PUBLIC eigen plog)