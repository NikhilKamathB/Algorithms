# Project configuration
set(PROJECT_VERSION_MAJOR 1 CACHE STRING "Major version" FORCE)
set(PROJECT_VERSION_MINOR 0 CACHE STRING "Minor version" FORCE)
set(PROJECT_VERSION_PATCH 0 CACHE STRING "Patch version" FORCE)

# Build/compile configuration
set(CMAKE_CXX_STANDARD "23" CACHE STRING "C++ standard to use")
set(EIGEN3_INCLUDE_DIR "../../third_party/eigen" CACHE STRING "Eigen3 include directory")

# Set global properties
set_property(GLOBAL PROPERTY CMAKE_CXX_STANDARD ${CMAKE_CXX_STANDARD})
set_property(GLOBAL PROPERTY EIGEN3_INCLUDE_DIR ${EIGEN3_INCLUDE_DIR})

# Include third party libraries
# Boost
find_package(Boost REQUIRED)