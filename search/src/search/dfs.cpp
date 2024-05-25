/**
 * @file dfs.cpp
 * @brief Contains the implementation of the `DFS` class.
*/

#include <deque>
#include <unordered_set>
#include <search/search/dfs.h>

namespace search {
    template <typename T, unsigned int D>
    DFS<T, D>::DFS() {}

    template <typename T, unsigned int D>
    DFS<T, D>::~DFS() {}

    template <typename T, unsigned int D>
    const std::vector<std::pair<Node<T, D>, T>> DFS<T, D>::solve(const Node<T, D>& start_node, const Node<T, D>& goal_node) const
    {   
        std::unordered_set<const Node<T, D>*> visited_nodes;
        std::unordered_map<const Node<T, D>*, std::pair<const Node<T, D>*, T>> parent_map_cost;
        std::deque<const Node<T, D>*> stack = {&start_node};
        while (!stack.empty())
        {
            const Node<T, D> *current_node = stack.back();
            stack.pop_back();
            if (visited_nodes.find(current_node) != visited_nodes.end())
            {
                continue;
            }
            visited_nodes.insert(current_node);
            if (*current_node == goal_node)
            {
                return this->getPath(start_node, goal_node, parent_map_cost);
            }
            std::vector<const Node<T, D>*> neighbors = current_node->getNeighbors();
            for (const Node<T, D> *neighbor : neighbors)
            {
                if (visited_nodes.find(neighbor) == visited_nodes.end())
                {
                    stack.push_back(neighbor);
                    if (parent_map_cost.find(neighbor) == parent_map_cost.end())
                    {
                        parent_map_cost[neighbor] = std::make_pair(current_node, current_node->getCost(*neighbor));
                    }
                }
            }
        }
        return std::vector<std::pair<Node<T, D>, T>>();
    }

    // Explicit template instantiation
    template class DFS<float, 1U>;
    template class DFS<float, 2U>;
    template class DFS<float, 3U>;
    template class DFS<double, 1U>;
    template class DFS<double, 2U>;
    template class DFS<double, 3U>;
}