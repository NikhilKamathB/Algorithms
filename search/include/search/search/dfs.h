#ifndef SEARCH_SEARCH_DFS_H
#define SEARCH_SEARCH_DFS_H

/**
 * @file dfs.h
 * @brief Contains the definition of the `DFS` class/implementation.
 */

#include <search/node.h>

namespace search {

    /**
     * @class DFS
     * @brief This class represents the Depth First Search algorithm.
     * @details An instance of the `DFS` class represents the Depth First Search algorithm.
     */

    template <typename T, unsigned int D>
    class DFS {

        private:
            /**
             * @brief Private members of `DFS`
             */
        
        public:
            /**
             * @brief Public members of `DFS`
             */

            /**
             * @brief Constructor of the `DFS` class.
             */
            DFS();

            /**
             * @brief Destructor of the `DFS` class.
             */
            ~DFS();

            /**
             * @brief Solve the search problem.
             * @param start_node - start node in the environment.
             * @param goal_node - goal node in the environment.
             * @return a vector of node names representing the path from the start node to the goal node.
            */
            const std::vector<Node<T, D>> solve(const Node<T, D>& start_node, const Node<T, D>& goal_node) const;
    };

} // namespace search

#endif // SEARCH_SEARCH_DFS_H