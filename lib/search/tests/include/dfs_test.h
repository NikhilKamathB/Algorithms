#ifndef SEARCH_TEST_DFS_H
#define SEARCH_TEST_DFS_H

/**
 * @file dfs_test.h
 * @brief Contains the declarations for testing DFS. Use this to define your helpers.
 */

#include <gtest/gtest.h>
#include <search/cost/default_cost.h>
#include <search/environment/graph.h>

namespace search
{

    namespace search_dfs_tests
    {
        struct DfsTestParameters
        {
            const std::size_t num_nodes;                                   // Number of nodes in the graph
            const std::size_t start_node_index;                            // Index of the start node
            const std::size_t goal_node_index;                             // Index of the goal node
            const std::vector<std::pair<std::size_t, std::size_t>> edges; // List of edges in the graph
            const std::vector<std::string> expected_result;                // Expected result of the DFS search
        };

        /**
         * @class DfsTest
         * @brief This class is a test fixture for testing the Depth First Search (DFS) algorithm.
         * It sets up a graph with nodes and edges for testing purposes.
         * @tparam T Type of the node value.
         * @tparam D Dimension of the node value.
         */
        class DfsTest : public ::testing::TestWithParam<DfsTestParameters>
        {
            using T = int;
            static constexpr unsigned int D = 1;

        protected:
            std::vector<std::string> result; // Path found by DFS search with names only for validation

            /**
             * @brief Set up the test fixture.
             */
            void SetUp() override
            {
                // Initialize or set up resources needed for tests
                DfsTestParameters props = GetParam();
                // Make nodes
                std::vector<std::unique_ptr<Node<T, D>>> nodes;
                for (std::size_t i = 0; i < props.num_nodes; ++i)
                {
                    nodes.emplace_back(std::make_unique<Node<T, D>>(NodeValue<T, D>(), std::to_string(i)));
                }
                // Set cost function
                DefaultCost<T, D> cost_function = DefaultCost<T, D>(); // Default cost of 1.0
                // Create the graph with the nodes and edges
                Graph<T, D> graph_evn = Graph<T, D>(nodes, props.edges, cost_function);
                // Initialize the graph environment
                graph_evn.initialize();
                // Run DFS search
                std::vector<std::pair<const Node<T, D> *, double>> path = graph_evn.search(
                    *graph_evn.get_node(props.start_node_index),
                    *graph_evn.get_node(props.goal_node_index),
                    utils::SearchAlgorithm::DFS);
                // Store the result
                result.clear();
                for (std::pair<const Node<T, D> *, double> &node_pair : path)
                {
                    result.emplace_back(node_pair.first->get_name());
                }
            }
        };
    }

} // namespace search

#endif // SEARCH_TEST_DFS_H