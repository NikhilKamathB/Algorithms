#ifndef SEARCH_SEARCH_BASE_H
#define SEARCH_SEARCH_BASE_H

/**
 * @file base.h
 * @brief Contains the definition of the `SearchBase` class.
 */

#include <search/node.h>

namespace search
{
    /**
     * @class SearchBase
     * @brief This class represents the base class for all search algorithms.
     * @details An instance of the `SearchBase` class represents the base class for all search algorithms.
     */
    template <typename T, unsigned int D>
    class SearchBase
    {
        private:
            /**
             * @brief Private members of `SearchBase`
             */

        public:
            /**
             * @brief Public members of `SearchBase`
             */

            /**
             * @brief Constructor of the `SearchBase` class.
             */
            SearchBase();

            /**
             * @brief Destructor of the `SearchBase` class.
             */
            ~SearchBase();

            // Get path from the start node to the goal node.
            const std::vector<Node<T, D>> getPath(
                const Node<T, D>& start_node,
                const Node<T, D>& goal_node,
                const std::unordered_map<const Node<T, D> *, const Node<T, D> *>& parent_map) const;

            /**
             * @brief Solve the search problem.
             * @param start_node - start node in the environment.
             * @param goal_node - goal node in the environment.
             * @return a vector of node names representing the path from the start node to the goal node.
            */
            virtual const std::vector<Node<T, D>> solve(const Node<T, D>& start_node, const Node<T, D>& goal_node) const;
    };

} // namespace search

#endif // SEARCH_SEARCH_BASE_H