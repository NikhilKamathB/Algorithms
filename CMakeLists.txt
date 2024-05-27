# CMake version
cmake_minimum_required(VERSION 3.29)

# Project name
project(algorithms)

# Global/Local settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configurations
set(PYTHON_DIR "/opt/miniconda3" CACHE PATH "Python directory")
set(PYTHON_EXECUTABLE "${PYTHON_DIR}/bin/python" CACHE PATH "Python executable")
set(PYTHON_INCLUDE_DIR "${PYTHON_DIR}/include/python3.9" CACHE PATH "Python include directory")
set(PYTHON_LIBRARY "${PYTHON_DIR}/lib/libpython3.9.dylib" CACHE PATH "Python library path")
message(STATUS "Set python executable: ${PYTHON_EXECUTABLE}")
message(STATUS "Set python include dir: ${PYTHON_INCLUDE_DIR}")
message(STATUS "Set python library: ${PYTHON_LIBRARY}")

# Include third party libraries
# Eigen
set(EIGEN3_INCLUDE_DIR ../third_party/eigen)

# Find all packages
find_package(Boost 1.85.0 REQUIRED COMPONENTS python)
message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost library dir: ${Boost_LIBRARIES}")

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
target_include_directories(algorithms PRIVATE ${PYTHON_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})
target_link_libraries(algorithms PRIVATE ${PYTHON_LIBRARY} ${Boost_LIBRARIES} algorithms_main)
set_target_properties(algorithms PROPERTIES PREFIX "")

# Add executables
# Algorithms - main | double | 1D
add_executable(algorithms_exec __main__.cpp)
target_link_libraries(algorithms_exec PRIVATE algorithms_main)
target_compile_definitions(algorithms_exec PRIVATE FLOATING_POINT_TYPE=double DIM=1U)