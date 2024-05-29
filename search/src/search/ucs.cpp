/**
 * @file usc.cpp
 * @brief Contains the implementation of the `USC` class.
 */

#include <search/search/ucs.h>

namespace search
{
    template <typename T, unsigned int D>
    UCS<T, D>::UCS() {}

    template <typename T, unsigned int D>
    UCS<T, D>::~UCS() {}

    template <typename T, unsigned int D>
    const std::vector<std::pair<Node<T, D>, T>> UCS<T, D>::solve(const Node<T, D> &start_node, const Node<T, D> &goal_node) const
    {
        std::unordered_set<const Node<T, D> *> visited_nodes;
        std::unordered_map<const Node<T, D> *, std::pair<const Node<T, D> *, T>> parent_map_cost;
        std::multiset<std::pair<const Node<T, D> *, T>, NodeGnComparator<T, D>> queue = {std::make_pair(&start_node, 0)};
        while (!queue.empty())
        {
            // Print content of queue
            const Node<T, D> *current_node = queue.begin()->first;
            T current_cost = queue.begin()->second;
            queue.erase(queue.begin());
            if (visited_nodes.find(current_node) != visited_nodes.end())
            {
                continue;
            }
            visited_nodes.insert(current_node);
            if (*current_node == goal_node)
            {
                return this->getPath(start_node, goal_node, parent_map_cost);
            }
            std::vector<const Node<T, D> *> neighbors = current_node->getNeighbors();
            for (const Node<T, D> *neighbor : neighbors)
            {
                if (visited_nodes.find(neighbor) == visited_nodes.end())
                {
                    T new_cost = current_cost + current_node->getCost(*neighbor);
                    queue.insert(std::make_pair(neighbor, new_cost));
                    if (parent_map_cost.find(neighbor) == parent_map_cost.end() || (parent_map_cost.find(neighbor) != parent_map_cost.end() && new_cost < parent_map_cost[neighbor].second))
                    {
                        parent_map_cost[neighbor] = std::make_pair(current_node, new_cost);
                    }
                }
            }
        }
        return std::vector<std::pair<Node<T, D>, T>>();
    }

    // Explicit template instantiation
    template class UCS<float, 1U>;
    template class UCS<float, 2U>;
    template class UCS<float, 3U>;
    template class UCS<double, 1U>;
    template class UCS<double, 2U>;
    template class UCS<double, 3U>;
}