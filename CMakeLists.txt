# CMake version
cmake_minimum_required(VERSION 3.29)

# Project name
project(algorithms)

# Global/Local settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configurations
set(PACKAGE_DESTINATION_DIR "." CACHE PATH "Destination directory for packages")

# Include third party libraries
# Eigen
set(EIGEN3_INCLUDE_DIR ../third_party/eigen)

# Find all packages
find_package(Boost 1.85.0 REQUIRED)

# Add implementations
get_property(is_search_ADDED GLOBAL PROPERTY search_ADDED)
if(NOT is_search_ADDED)
    add_subdirectory(./search ${CMAKE_CURRENT_BINARY_DIR}/search)
endif()

# Make package
add_library(algorithms SHARED 
    algorithms.cpp)
target_include_directories(algorithms PUBLIC include)
target_link_libraries(algorithms PUBLIC search_environment)

# Add executables
# Algorithms - main | double | 1D
add_executable(algorithms_main main.cpp)
target_link_libraries(algorithms_main PRIVATE algorithms)
target_compile_definitions(algorithms_main PRIVATE FLOATING_POINT_TYPE=double DIM=1U)