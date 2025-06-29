/**
 * @file dfs_test.cpp
 * @brief Unit tests for the Depth First Search (DFS) algorithm.
 */

#include <gtest/gtest.h>
#include <dfs_test.h>

namespace search
{
    namespace search_dfs_tests
    {
        INSTANTIATE_TEST_SUITE_P(
            DfsTestSuite,
            DfsTest,
            ::testing::Values(
                DfsTestParameters{
                    5,                                // Number of nodes in the graph
                    0,                                // Index of the start node
                    4,                                // Index of the goal node
                    {{0, 1}, {1, 2}, {2, 3}, {3, 4}}, // List of edges in the graph
                    {"0", "1", "2", "3", "4"}},       // Expected result of the DFS search
                DfsTestParameters{
                    4,
                    0,
                    3,
                    {{0, 1}, {0, 2}, {1, 3}, {2, 3}},
                    {"0", "2", "3"}}
                ));

        TEST_P(DfsTest, SearchPathExists)
        {
            // Get the parameters for the test
            DfsTestParameters props = GetParam();
            // Check if the result contains the expected path
            EXPECT_EQ(result, props.expected_result)
                << "The path for DFS search does not match the expected result";
        }
    }
    }