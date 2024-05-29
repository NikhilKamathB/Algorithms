/**
 * @file main.cpp
 * @brief Contains the main function to run the algorithms library - contains hard-coded values.
 * `algorithms.h` will be used to run algorithms through wrappers.
 */

#include <iostream>
#include <algorithms.h>

using T = FLOATING_POINT_TYPE;  // Data type - [double, float]
constexpr unsigned int D = DIM; // Dimensions - [1, 2, 3]

// Definitions for the `Algorithm` class.
using RowVector = Eigen::Matrix<T, 1, D>;
using Node = search::Node<T, D>;

void printPath(const std::vector<std::pair<Node, T>> &path)
{
    for (std::size_t i = 0; i < path.size(); ++i)
    {
        std::cout << path[i].first.getName() << " (" << path[i].second << ")";
        if (i < path.size() - 1)
        {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    // Create an instance of the `Algorithm` class.
    algorithms::Algorithm<T, D> algorithm = algorithms::Algorithm<double, 1>();
    // Perform search using the `Breadth First Search` algorithm.
    std::size_t _num_nodes = 6;
    std::vector<std::pair<std::size_t, std::size_t>> _edges = {
        {0, 1},
        {0, 2},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4},
        {3, 5},
        {4, 5}};
    std::vector<RowVector> _node_values = {
        RowVector{0.0},
        RowVector{1.0},
        RowVector{1.0},
        RowVector{2.0},
        RowVector{9.0},
        RowVector{6.0}};
    // Search - BFS
    std::cout << "Running `search` algorithm using the `Breadth First Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> bfs_path = algorithm.search(_num_nodes, _node_values, {}, _edges, 0, 5, search::SearchAlgorithm::BREADTH_FIRST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(bfs_path);
    // Search - DFS
    std::cout << "Running `search` algorithm using the `Depth First Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> dfs_path = algorithm.search(_num_nodes, _node_values, {}, _edges, 0, 5, search::SearchAlgorithm::DEPTH_FIRST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(dfs_path);
    // Search - UCS
    std::cout << "Running `search` algorithm using the `Uniform Cost Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> ucs_path = algorithm.search(_num_nodes, _node_values, {}, _edges, 0, 5, search::SearchAlgorithm::UNIFORM_COST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(ucs_path);
    return 0;
}