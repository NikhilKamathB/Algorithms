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
    const std::vector<Node<T, D>> SearchBase<T, D>::getPath(
        const Node<T, D>& start_node,
        const Node<T, D>& goal_node,
        const std::unordered_map<const Node<T, D>*, const Node<T, D>*>& parent_map) const
    {
        std::vector<Node<T, D>> path;
        const Node<T, D> *current_node = &goal_node;
        while (*current_node != start_node)
        {
            path.push_back(*current_node);
            current_node = parent_map.at(current_node);
        }
        path.push_back(start_node);
        std::reverse(path.begin(), path.end());
        return path;
    }

    template <typename T, unsigned int D>
    const std::vector<Node<T, D>> SearchBase<T, D>::solve(const Node<T, D>& start_node, const Node<T, D>& goal_node) const
    {
        return {};
    }

    // Explicit template instantiation
    template class SearchBase<float, 1U>;
    template class SearchBase<float, 2U>;
    template class SearchBase<float, 3U>;
    template class SearchBase<double, 1U>;
    template class SearchBase<double, 2U>;
    template class SearchBase<double, 3U>;
}