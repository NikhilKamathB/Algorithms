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
                    {{0, 1}, {1, 2}, {2, 3}, {3, 4}}, // List of edges in the graph - linear graph
                    {"0", "1", "2", "3", "4"}},       // Expected result of the DFS search
                DfsTestParameters{
                    1,
                    0,
                    0,
                    {}, // Single Node
                    {"0"}},
                DfsTestParameters{
                    4,
                    2,
                    3,
                    {{0, 1}, {1, 2}, {2, 0}, {1, 3}}, // Cycle - 1 in Graph
                    {"2", "0", "1", "3"}},
                DfsTestParameters{
                    5,
                    4,
                    2,
                    {{0, 1}, {1, 2}, {2, 1}, {2, 3}, {3, 0}, {3, 4}, {4, 3}}, // Cycle - 2 in Graph
                    {"4", "3", "0", "1", "2"}},
                DfsTestParameters{
                    6,
                    0,
                    5,
                    {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}}, // Star structure in Graph
                    {"0", "5"}},
                DfsTestParameters{
                    3,
                    0,
                    2,
                    {{0, 0}, {0, 1}, {1, 2}}, // Self loop in Graph`
                    {"0", "1", "2"}},
                DfsTestParameters{
                    4,
                    0,
                    3,
                    {{0, 1}, {0, 2}, {1, 3}, {2, 3}}, // List of edges in the graph - tree structure
                    {"0", "2", "3"}},
                DfsTestParameters{
                    6,
                    0,
                    5,
                    {{0, 1}, {0, 2}, {1, 4}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}}, // List of edges in the graph - simple graph
                    {"0", "2", "4", "5"}},
                DfsTestParameters{
                    16,
                    0,
                    15,
                    {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {2, 7}, {3, 7}, {3, 10}, {3, 11}, {3, 12}, {4, 5}, {4, 7}, {5, 6}, {6, 13}, {7, 8}, {8, 9}, {9, 13}, {9, 15}, {10, 11}, {10, 13}, {11, 12}, {11, 14}, {12, 14}, {13, 15}}, // List of edges in the graph - complex structure
                    {"0", "2", "7", "8", "9", "15"}}));

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