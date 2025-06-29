#ifndef SEARCH_SEARCH_SEARCH_H
#define SEARCH_SEARCH_SEARCH_H

/**
 * @file search.h
 * @brief Abstract class for representing search algorithms. This is mostly a pure virtual class and must be inherited to define a custom search algorithm.
 */

#include <plog/Log.h>
#include <search/node/node.h>
#include <search/environment/environment.h>

namespace search
{

    /**
     * @class Search
     * @brief Search class that represents a search algorithm in a given environment.
     * @tparam T Type.
     * @tparam D Dimension.
     * @tparam E Environment type.
     */
    template <typename T, unsigned int D, typename E>
        requires(std::derived_from<E, Environment<T, D>>)
    class Search
    {

    public:
        /**
         * @brief Construct a new Search object.
         */
        Search() = default;

        /**
         * Destructor for the Search class.
         */
        virtual ~Search() = default;

        /**
         * @brief Perform a search on graph based environment and return paths from start to goal.
         * @param start_node The starting node.
         * @param goal_node The goal node.
         * @param env The environment in which the search is performed.
         * @return A vectors of pairs representing the paths from start to goal along with their step costs.
         */
        virtual const std::vector<std::pair<const Node<T, D> *, double>> search(
            const Node<T, D> &start_node,
            const Node<T, D> &goal_node,
            const E &env) const = 0;

        /**
         * @brief Get the path from `from_node` to `to_node` in the environment given the parent map.
         * @param from_node node A.
         * @param to_node node B.
         * @param parent_map A map of nodes to their parent nodes and the cost to reach them.
         * @return const std::vector<std::pair<Node<T, D> *, double>> path from `from_node` to `to_node`.
         */
        virtual const std::vector<std::pair<const Node<T, D> *, double>> get_path(const Node<T, D> &from_node,
                                                                            const Node<T, D> &to_node,
                                                                            const std::unordered_map<const Node<T, D> *, std::pair<const Node<T, D> *, double>> &parent_map) const
        {
            PLOGD << "Getting path from node: " << from_node.get_name() << " to node: " << to_node.get_name();
            std::vector<std::pair<const Node<T, D> *, double>> path;
            const Node<T, D> *node = &to_node;
            while (node != nullptr && *node != from_node)
            {
                path.emplace_back(node, parent_map.at(node).second);
                node = parent_map.at(node).first;
            }
            path.emplace_back(&from_node, 0.0); // Add the starting node with cost 0
            std::reverse(path.begin(), path.end());
            return path;
        }
    };

} // namespace search

#endif // SEARCH_SEARCH_SEARCH_H