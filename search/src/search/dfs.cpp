/**
 * @file dfs.cpp
 * @brief Contains the implementation of the `DFS` class.
*/

#include <search/search/dfs.h>

namespace search {
    template <typename T, unsigned int D>
    DFS<T, D>::DFS() {}

    template <typename T, unsigned int D>
    DFS<T, D>::~DFS() {}

    template <typename T, unsigned int D>
    const std::vector<Node<T, D>> DFS<T, D>::solve(const Node<T, D>& start_node, const Node<T, D>& goal_node) const
    {
        std::vector<const Node<T, D>*> path = {&start_node};
        std::vector<const Node<T, D>*> visited_nodes = {&start_node};
        while (!visited_nodes.empty())
        {
            const Node<T, D> *current_node = visited_nodes.back();
            visited_nodes.pop_back();
            if (*current_node == goal_node)
            {
                return {start_node};
            }
            std::vector<const Node<T, D>*> neighbors = current_node->getNeighbors();
            for (const Node<T, D> *neighbor : neighbors)
            {
                if (std::find(visited_nodes.begin(), visited_nodes.end(), neighbor) == visited_nodes.end())
                {
                    visited_nodes.push_back(neighbor);
                    path.push_back(neighbor);
                }
            }
        }
        return { start_node };
    }

    // Explicit template instantiation
    template class DFS<float, 1U>;
    template class DFS<float, 2U>;
    template class DFS<float, 3U>;
    template class DFS<double, 1U>;
    template class DFS<double, 2U>;
    template class DFS<double, 3U>;
}