# CMake version
cmake_minimum_required(VERSION 3.31)

# Project metadata
set(PROJECT_NAME search_tests)
project(${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "Tests for Search library.")
message(STATUS "Configuring project: ${PROJECT_NAME} v${PROJECT_VERSION}...")

# Include third party libraries
# Custom libraries
if (NOT TARGET utils)
    add_subdirectory(../../utils ${CMAKE_CURRENT_BINARY_DIR}/utils)
endif()
if (NOT TARGET math)
    add_subdirectory(../../math ${CMAKE_CURRENT_BINARY_DIR}/math)
endif()
if (NOT TARGET search)
    add_subdirectory(../../search ${CMAKE_CURRENT_BINARY_DIR}/search)
endif()

# ---------------------------------- Test search ---------------------------------------
# Test DFS
add_executable(dfs_test src/dfs_test.cpp)
target_include_directories(dfs_test
    PRIVATE
        include
        ../include
)
target_link_libraries(dfs_test
    PRIVATE
        utils
        math
        search
        GTest::gtest_main
)
add_test(NAME dfs_test COMMAND dfs_test) 

# ---------------------------------- Confimation ---------------------------------------
message(NOTICE "Configured: ${PROJECT_NAME} v${PROJECT_VERSION}")