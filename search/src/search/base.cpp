/**
 * @file base.cpp
 * @brief Contains the implementation of the `SearchBase` class.
 */

#include <search/search/base.h>

namespace search {
    template <typename T, unsigned int D>
    SearchBase<T, D>::SearchBase() {}

    template <typename T, unsigned int D>
    SearchBase<T, D>::~SearchBase() {}

    template <typename T, unsigned int D>
    const std::vector<std::pair<Node<T, D>, T>> SearchBase<T, D>::getPath(
        const Node<T, D>& start_node,
        const Node<T, D>& goal_node,
        const std::unordered_map<const Node<T, D> *, std::pair<const Node<T, D> *, T>>& parent_map) const
    {
        std::vector<std::pair<Node<T, D>, T>> path;
        const Node<T, D> *current_node = &goal_node;
        while (*current_node != start_node)
        {
            std::pair<Node<T, D>, T> node_cost = std::make_pair(*current_node, parent_map.at(current_node).second);
            path.push_back(node_cost);
            current_node = parent_map.at(current_node).first;
        }
        path.push_back(std::make_pair(start_node, 0));
        std::reverse(path.begin(), path.end());
        return path;
    }

    // Explicit template instantiation
    template class SearchBase<float, 1U>;
    template class SearchBase<float, 2U>;
    template class SearchBase<float, 3U>;
    template class SearchBase<double, 1U>;
    template class SearchBase<double, 2U>;
    template class SearchBase<double, 3U>;
}