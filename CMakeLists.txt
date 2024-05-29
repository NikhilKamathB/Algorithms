# CMake version
cmake_minimum_required(VERSION 3.29)

# Project name
project(algorithms)

# Global/Local settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include third party libraries
# Pybind11
if(NOT TARGET pybind11)
    add_subdirectory(./third_party/pybind11 ${CMAKE_CURRENT_BINARY_DIR}/pybind11)
endif()

# Add implementations
get_property(is_search_ADDED GLOBAL PROPERTY search_ADDED)
if(NOT is_search_ADDED)
    add_subdirectory(./search ${CMAKE_CURRENT_BINARY_DIR}/search)
endif()

# Algorithms
add_library(algorithms_main SHARED 
    algorithms.cpp)
target_include_directories(algorithms_main PUBLIC include)
target_link_libraries(algorithms_main PUBLIC search_environment)

# Driver lib
add_library(algorithms MODULE
    main.cpp)
target_include_directories(algorithms PRIVATE ${pybind11_INCLUDE_DIRS})
target_link_libraries(algorithms PRIVATE pybind11::module algorithms_main)
set_target_properties(algorithms PROPERTIES PREFIX "")

# Add executables
# Algorithms - main | double | 1D
add_executable(algorithms_exec __main__.cpp)
target_link_libraries(algorithms_exec PRIVATE algorithms_main)
target_compile_definitions(algorithms_exec PRIVATE FLOATING_POINT_TYPE=double DIM=1U)