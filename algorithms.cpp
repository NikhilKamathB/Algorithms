/**
 * @file algorithms.cpp
 * @brief Contains the implementation of all algorithms.
 */

#include <algorithms.h>

namespace algorithms
{
    template <typename T, unsigned int D>
    Algorithm<T, D>::Algorithm() {}

    template <typename T, unsigned int D>
    Algorithm<T, D>::~Algorithm() {}

    template <typename T, unsigned int D>
    const std::vector<std::pair<typename Algorithm<T, D>::Node, T>> Algorithm<T, D>::_search(
        const std::size_t &num_nodes,
        const std::vector<RowVector> &node_values,
        const std::vector<std::string> &node_names,
        const std::vector<std::pair<std::size_t, std::size_t>> &edges,
        const std::size_t &start_node_idx,
        const std::size_t &goal_node_idx,
        const SearchAlgorithm &method,
        const DistanceMetric &distance_metric,
        const std::string &node_prefix_name,
        const bool &use_node_value,
        const bool &bidirectional) const
    {
        using Environment = search::Environment<T, D>;
        // Instantiate the `Environment` class.
        Environment env(
            /*num_nodes=*/num_nodes,
            /*edges=*/edges,
            /*distance_metric=*/distance_metric,
            /*node_prefix_name=*/node_prefix_name,
            /*use_node_value=*/use_node_value,
            /*bidirectional=*/bidirectional);
        // Create the environment.
        env.create(
            /*node_values=*/node_values,
            /*node_names=*/node_names);
        // Solve the search problem.
        return env.search(
            /*start_node=*/env.getNode(start_node_idx),
            /*goal_node=*/env.getNode(goal_node_idx),
            /*method=*/method);
    }

    template <typename T, unsigned int D>
    const std::vector<std::pair<typename Algorithm<T, D>::Node, T>> Algorithm<T, D>::search(
        const std::size_t &num_nodes,
        const std::vector<RowVector> &node_values,
        const std::vector<std::string> &node_names,
        const std::vector<std::pair<std::size_t, std::size_t>> &edges,
        const std::size_t &start_node_idx,
        const std::size_t &goal_node_idx,
        const SearchAlgorithm &method,
        const DistanceMetric &distance_metric,
        const std::string &node_prefix_name,
        const bool &use_node_value,
        const bool &bidirectional) const
    {
        // Solve the search problem.
        const std::vector<std::pair<Node, T>> result = this->_search(
            /*num_nodes=*/num_nodes,
            /*node_values=*/node_values,
            /*node_names=*/node_names,
            /*edges=*/edges,
            /*start_node_idx=*/start_node_idx,
            /*goal_node_idx=*/goal_node_idx,
            /*method=*/method,
            /*distance_metric=*/distance_metric,
            /*node_prefix_name=*/node_prefix_name,
            /*use_node_value=*/use_node_value,
            /*bidirectional=*/bidirectional);
        return result;
    }

    // Explicit instantiation of the template class.
    template class Algorithm<float, 1U>;
    template class Algorithm<float, 2U>;
    template class Algorithm<float, 3U>;
    template class Algorithm<double, 1U>;
    template class Algorithm<double, 2U>;
    template class Algorithm<double, 3U>;

} // namespace algorithms