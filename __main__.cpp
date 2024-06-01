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
    std::size_t _num_nodes_1 = 6;
    std::vector<std::pair<std::size_t, std::size_t>> _edges_1 = {
        {0, 1},
        {0, 2},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4},
        {3, 5},
        {4, 5}};
    std::vector<RowVector> _node_values_1 = {
        RowVector{0.0},
        RowVector{1.0},
        RowVector{1.0},
        RowVector{2.0},
        RowVector{9.0},
        RowVector{6.0}};
    std::size_t _num_nodes_2 = 16;
    std::vector<std::pair<std::size_t, std::size_t>> _edges_2 = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 3},
        {2, 4},
        {2, 7},
        {3, 7},
        {3, 10},
        {3, 11},
        {3, 12},
        {4, 5},
        {4, 7},
        {5, 6},
        {6, 13},
        {7, 8},
        {8, 9},
        {9, 13},
        {9, 15},
        {10, 11},
        {10, 13},
        {11, 12},
        {11, 14},
        {12, 14},
        {13, 15}};
    std::vector<RowVector> _node_values_2 = {
        RowVector{0.0},
        RowVector{10.0},
        RowVector{1.0},
        RowVector{2.0},
        RowVector{10.0},
        RowVector{15.0},
        RowVector{20.0},
        RowVector{20.0},
        RowVector{25.0},
        RowVector{5.0},
        RowVector{5.0},
        RowVector{4.0},
        RowVector{3.0},
        RowVector{5.0},
        RowVector{3.0},
        RowVector{20.0}};
    std::cout << "============================================================" << std::endl;
    // Search - BFS
    std::cout << "EXPERIMENT 1: Running `search` algorithm using the `Breadth First Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> bfs_path_1 = algorithm.search(_num_nodes_1, _node_values_1, {}, _edges_1, 0, 5, search::SearchAlgorithm::BREADTH_FIRST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(bfs_path_1);
    // Search - DFS
    std::cout << "EXPERIMENT 1: Running `search` algorithm using the `Depth First Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> dfs_path_1 = algorithm.search(_num_nodes_1, _node_values_1, {}, _edges_1, 0, 5, search::SearchAlgorithm::DEPTH_FIRST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(dfs_path_1);
    // Search - UCS
    std::cout << "EXPERIMENT 1: Running `search` algorithm using the `Uniform Cost Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> ucs_path_1 = algorithm.search(_num_nodes_1, _node_values_1, {}, _edges_1, 0, 5, search::SearchAlgorithm::UNIFORM_COST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(ucs_path_1);
    // Search - A*
    std::cout << "EXPERIMENT 1: Running `search` algorithm using the `A*` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> a_star_path_1 = algorithm.search(_num_nodes_1, _node_values_1, {}, _edges_1, 0, 5, search::SearchAlgorithm::A_STAR, search::DistanceMetric::MANHATTAN);
    printPath(a_star_path_1);
    std::cout << "============================================================" << std::endl;
    // Search - BFS
    std::cout << "EXPERIMENT 2: Running `search` algorithm using the `Breadth First Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> bfs_path_2 = algorithm.search(_num_nodes_2, _node_values_2, {}, _edges_2, 0, 15, search::SearchAlgorithm::BREADTH_FIRST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(bfs_path_2);
    // Search - DFS
    std::cout << "EXPERIMENT 2: Running `search` algorithm using the `Depth First Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> dfs_path_2 = algorithm.search(_num_nodes_2, _node_values_2, {}, _edges_2, 0, 15, search::SearchAlgorithm::DEPTH_FIRST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(dfs_path_2);
    // Search - UCS
    std::cout << "EXPERIMENT 2: Running `search` algorithm using the `Uniform Cost Search` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> ucs_path_2 = algorithm.search(_num_nodes_2, _node_values_2, {}, _edges_2, 0, 15, search::SearchAlgorithm::UNIFORM_COST_SEARCH, search::DistanceMetric::MANHATTAN);
    printPath(ucs_path_2);
    // Search - A*
    std::cout << "EXPERIMENT 2: Running `search` algorithm using the `A*` algorithm." << std::endl;
    const std::vector<std::pair<Node, T>> a_star_path_2 = algorithm.search(_num_nodes_2, _node_values_2, {}, _edges_2, 0, 15, search::SearchAlgorithm::A_STAR, search::DistanceMetric::MANHATTAN);
    printPath(a_star_path_2);
    std::cout << "============================================================" << std::endl;
    return 0;
}