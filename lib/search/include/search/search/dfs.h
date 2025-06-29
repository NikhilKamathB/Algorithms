#ifndef SEARCH_DFS_H
#define SEARCH_DFS_H

/**
 * @file dfs.h
 * @brief Depth-First Search (DFS) algorithm implementation for graph-based environments.
 */

#include <queue>
#include <unordered_set>
#include <search/search/search.h>

namespace search
{
    /**
     * @class DFS
     * @brief This class represents the Depth-First Search (DFS) algorithm for searching in an environment.
     * @tparam T Type.
     * @tparam D Dimension.
     * @tparam E Environment type.
     */
    template <typename T, unsigned int D, typename E>
        requires(std::derived_from<E, Environment<T, D>>)
    class DFS : protected Search<T, D, E>
    {
    public:
        /**
         * @brief Construct a new DFS object.
         */
        DFS()
        {
            PLOGD << "Initializing DFS object.";
        }

        /**
         * @brief Destructor for the DFS class.
         */
        ~DFS()
        {
            PLOGD << "Destroying DFS object.";
        }

        /**
         * @brief Perform DFS search on graph based environment and return paths from start to goal.
         * @param start_node The starting node.
         * @param goal_node The goal node.
         * @param env The environment in which the search is performed.
         * @return A vectors of pairs representing the paths from start to goal along with their step costs.
         */
        const std::vector<std::pair<const Node<T, D> *, double>> search(
            const Node<T, D> &start_node,
            const Node<T, D> &goal_node,
            const E &env) const override
        {
            PLOGD << "Performing DFS search from node: " << start_node.get_name() << " to node: " << goal_node.get_name();
            std::unordered_set<const Node<T, D> *> visited_nodes;
            std::unordered_map<const Node<T, D> *, std::pair<const Node<T, D> *, double>> parent_cost_map;
            std::deque<const Node<T, D> *> stack = {&start_node};
            while (!stack.empty())
            {
                const Node<T, D> *current_node = stack.back();
                double cost = parent_cost_map[current_node].second;
                if (*current_node == goal_node)
                {
                    return this->get_path(start_node, goal_node, parent_cost_map);
                }
                stack.pop_back();
                if (visited_nodes.find(current_node) == visited_nodes.end())
                {
                    visited_nodes.insert(current_node);
                    for (const Node<T, D> *neighbor : current_node->get_neighbors())
                    {
                        if (visited_nodes.find(neighbor) == visited_nodes.end())
                        {
                            stack.push_back(neighbor);
                            if (parent_cost_map.find(neighbor) == parent_cost_map.end())
                            {
                                parent_cost_map[neighbor] = std::make_pair(current_node, cost + env.get_cost(*current_node, *neighbor));
                            }
                        }
                    }
                }
            }
            return {};
        }
    };

} // namespace search

#endif // SEARCH_DFS_H