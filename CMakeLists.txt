# CMake version
cmake_minimum_required(VERSION 3.31)

# Import CMake modules
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake)

# Project metadata
set(PROJECT_NAME algorithms)
project(${PROJECT_NAME} VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
message(STATUS "Composing project: ${PROJECT_NAME} v${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Include third party libraries
# Pybind11
if(NOT TARGET pybind11)
    add_subdirectory(./third_party/pybind11 ${CMAKE_CURRENT_BINARY_DIR}/pybind11)
endif()

# Add implementations
get_property(INCLUDE_SEARCH GLOBAL PROPERTY PACKAGE_INCLUDE_SEARCH)
if(INCLUDE_SEARCH)
    add_subdirectory(./lib/search ${CMAKE_CURRENT_BINARY_DIR}/search)
endif()

# # Algorithmst
# add_library(algorithms_main SHARED 
#     algorithms.cpp)
# target_include_directories(algorithms_main PUBLIC include)
# target_link_libraries(algorithms_main PUBLIC search_environment)

# # Driver lib
# add_library(algorithms MODULE
#     main.cpp)
# target_include_directories(algorithms PRIVATE ${pybind11_INCLUDE_DIRS})
# target_link_libraries(algorithms PRIVATE pybind11::module algorithms_main)
# set_target_properties(algorithms PROPERTIES PREFIX "")

# # Add executables
# # Algorithms - main | double | 1D
# add_executable(algorithms_exec __main__.cpp)
# target_link_libraries(algorithms_exec PRIVATE algorithms_main)
# target_compile_definitions(algorithms_exec PRIVATE FLOATING_POINT_TYPE=double DIM=1U)