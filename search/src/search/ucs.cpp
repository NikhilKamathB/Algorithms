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
        std::priority_queue<std::pair<const Node<T, D> *, T>, std::vector<std::pair<const Node<T, D> *, T>>, NodeGnComparator<T, D>> p_queue;
        p_queue.push(std::make_pair(&start_node, 0));
        while (!p_queue.empty())
        {
            // Print content of p_queue
            const Node<T, D> *current_node = p_queue.top().first;
            T current_cost = p_queue.top().second;
            p_queue.pop();
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
                    p_queue.push(std::make_pair(neighbor, new_cost));
                    if (parent_map_cost.find(neighbor) == parent_map_cost.end() || (parent_map_cost.find(neighbor) != parent_map_cost.end() && new_cost < parent_map_cost[neighbor].second))
                    {
                        parent_map_cost[neighbor] = std::make_pair(current_node, new_cost);
                    }
                }
            }
        }
        return std::vector<std::pair<Node<T, D>, T>>();
    }

    template <typename T, unsigned int D>
    bool NodeGnComparator<T, D>::operator()(const std::pair<const Node<T, D> *, T> &lhs, const std::pair<const Node<T, D> *, T> &rhs) const
    {
        return lhs.second > rhs.second;
    }

    // Explicit template instantiation
    template class UCS<float, 1U>;
    template class UCS<float, 2U>;
    template class UCS<float, 3U>;
    template class UCS<double, 1U>;
    template class UCS<double, 2U>;
    template class UCS<double, 3U>;
}