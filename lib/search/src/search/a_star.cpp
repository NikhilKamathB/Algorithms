/**
 * @file a_star.cpp
 * @brief Contains the implementation of the `AStar` class.
*/

#include <search/search/a_star.h>

namespace search {
    template <typename T, unsigned int D>
    AStar<T, D>::AStar() {}

    template <typename T, unsigned int D>
    AStar<T, D>::~AStar() {}

    template <typename T, unsigned int D>
    const std::vector<std::pair<Node<T, D>, T>> AStar<T, D>::solve(const Node<T, D> &start_node, const Node<T, D> &goal_node) const {
        std::unordered_set<const Node<T, D> *> visited_nodes;
        std::unordered_map<const Node<T, D> *, std::pair<const Node<T, D> *, T>> parent_map_cost;
        parent_map_cost[&start_node] = std::make_pair(nullptr, 0);
        // `p_queue` stores <Node, g(n) + h(n)> pairs
        std::priority_queue<std::pair<const Node<T, D> *, T>, std::vector<std::pair<const Node<T, D> *, T>>, NodeFnComparator<T, D>> p_queue;
        p_queue.push(std::make_pair(&start_node, 0 + start_node.getHeuristicCost(goal_node)));
        while (!p_queue.empty()) {
            const Node<T, D> *current_node = p_queue.top().first;
            T current_cost = parent_map_cost[current_node].second;
            p_queue.pop();
            if (visited_nodes.find(current_node) != visited_nodes.end()) {
                continue;
            }
            visited_nodes.insert(current_node);
            if (*current_node == goal_node) {
                return this->getPath(start_node, goal_node, parent_map_cost);
            }
            std::vector<const Node<T, D> *> neighbors = current_node->getNeighbors();
            for (const Node<T, D> *neighbor : neighbors) {
                if (visited_nodes.find(neighbor) == visited_nodes.end()) {
                    T gn = current_node->getCost(*neighbor);
                    T hn = neighbor->getHeuristicCost(goal_node);
                    T new_cost = current_cost + gn + hn;
                    p_queue.push(std::make_pair(neighbor, new_cost));
                    if (parent_map_cost.find(neighbor) == parent_map_cost.end() || (parent_map_cost.find(neighbor) != parent_map_cost.end() && gn < parent_map_cost[neighbor].second)) {
                        parent_map_cost[neighbor] = std::make_pair(current_node, current_cost + gn);
                    }
                }
            }
        }
        return std::vector<std::pair<Node<T, D>, T>>();
    }

    // Explicit template instantiation
    template class AStar<float, 1U>;
    template class AStar<float, 2U>;
    template class AStar<float, 3U>;
    template class AStar<double, 1U>;
    template class AStar<double, 2U>;
    template class AStar<double, 3U>;
}