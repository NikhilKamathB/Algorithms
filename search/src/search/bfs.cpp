/**
 * @file bfs.cpp
 * @brief Contains the implementation of the `BFS` class.
 */

#include <search/search/bfs.h>

namespace search
{
    template <typename T, unsigned int D>
    BFS<T, D>::BFS() {}

    template <typename T, unsigned int D>
    BFS<T, D>::~BFS() {}

    template <typename T, unsigned int D>
    const std::vector<std::pair<Node<T, D>, T>> BFS<T, D>::solve(const Node<T, D> &start_node, const Node<T, D> &goal_node) const
    {
        std::unordered_set<const Node<T, D> *> visited_nodes;
        std::unordered_map<const Node<T, D> *, std::pair<const Node<T, D> *, T>> parent_map_cost;
        std::deque<const Node<T, D> *> queue = {&start_node};
        while (!queue.empty())
        {
            const Node<T, D> *current_node = queue.front();
            T current_cost = parent_map_cost[current_node].second;
            queue.pop_front();
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
                    queue.push_back(neighbor);
                    if (parent_map_cost.find(neighbor) == parent_map_cost.end())
                    {
                        parent_map_cost[neighbor] = std::make_pair(current_node, current_cost + current_node->getCost(*neighbor));
                    }
                }
            }
        }
        return std::vector<std::pair<Node<T, D>, T>>();
    }

    // Explicit template instantiation
    template class BFS<float, 1U>;
    template class BFS<float, 2U>;
    template class BFS<float, 3U>;
    template class BFS<double, 1U>;
    template class BFS<double, 2U>;
    template class BFS<double, 3U>;
}