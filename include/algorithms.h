#ifndef ALGORITHMS_H
#define ALGORITHMS_H

/**
 * @file algorithms.h
 * @brief Contains utility functions/definitions used in the algorithms library.
 */

#include <search/environment.h>

namespace algorithms
{
    /**
     * @class Algorithm
     * @brief This class contains all the algorithms implemented in the library.
     * @details Algorithms implemented in the library are:
     * 1. Search Algorithms
     *     - Breadth First Search
     *     - Depth First Search
     *     - Uniform Cost Search
    */
   template <typename T, unsigned int D>
   class Algorithm
   {
       using RowVector = Eigen::Matrix<T, 1, D>;
       using Node = search::Node<T, D>;
       using SearchAlgorithm = search::SearchAlgorithm;
       using DistanceMetric = search::DistanceMetric;

   private:
       /**
        * @brief Private members of `Algorithm`
        */

       // Solve the search problem.
       const std::vector<std::pair<Node, T>> _search(
           const std::size_t &num_nodes,
           const std::vector<RowVector> &node_values,
           const std::vector<std::string> &node_names,
           const std::vector<std::pair<std::size_t, std::size_t>> &edges,
           const std::size_t &start_node_idx,
           const std::size_t &goal_node_idx,
           const SearchAlgorithm &method = SearchAlgorithm::BREADTH_FIRST_SEARCH,
           const DistanceMetric &distance_metric = DistanceMetric::EUCLIDEAN,
           const std::string &node_prefix_name = "Node_",
           const bool &use_node_value = true,
           const bool &bidirectional = true) const;

   public:
       /**
        * @brief Public members of `Algorithm`
        */

       /**
        * @brief Constructor of the `Algorithm` class.
        */
       Algorithm();

       /**
        * @brief Destructor of the `Algorithm` class.
        */
       ~Algorithm();

       /**
        * @brief Solve the search problem.
        * @param num_nodes - number of nodes in the environment.
        * @param node_values - values of the nodes in the environment.
        * @param node_names - names of the nodes in the environment.
        * @param edges - edges between the nodes in the environment.
        * @param start_node_idx - index of the start node.
        * @param goal_node_idx - index of the goal node.
        * @param method - search algorithm to use, default is `BREADTH_FIRST_SEARCH`.
        * @param distance_metric - distance metric used to compute the cost, default is `EUCLIDEAN`.
        * @param node_prefix_name - prefix name for the nodes in the environment, default is `Node_`.
        * @param use_node_value - flag to use the node value or not for computing the cost, default is `true`.
        * @param bidirectional - flag to create bidirectional edges between the nodes, default is `true`.
        */
       const std::vector<std::pair<Node, T>> search(
           const std::size_t &num_nodes,
           const std::vector<RowVector> &node_values,
           const std::vector<std::string> &node_names,
           const std::vector<std::pair<std::size_t, std::size_t>> &edges,
           const std::size_t &start_node_idx,
           const std::size_t &goal_node_idx,
           const SearchAlgorithm &method = SearchAlgorithm::BREADTH_FIRST_SEARCH,
           const DistanceMetric &distance_metric = DistanceMetric::EUCLIDEAN,
           const std::string &node_prefix_name = "Node_",
           const bool &use_node_value = true,
           const bool &bidirectional = true) const;
    };
} // namespace algorithms

#endif // ALGORITHMS_H