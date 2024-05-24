#ifndef SEARCH_SEARCH_BFS_H
#define SEARCH_SEARCH_BFS_H

/**
 * @file bfs.h
 * @brief Contains the definition of the `BFS` class/implementation.
*/

#include <search/search/base.h>

namespace search {

    /**
     * @class BFS
     * @brief This class represents the Breadth First Search algorithm.
     * @details An instance of the `BFS` class represents the Breadth First Search algorithm.
    */

    template <typename T, unsigned int D>
    class BFS: public SearchBase<T, D> {
    
         private:
            /**
            * @brief Private members of `BFS`
            */
    
         public:
            /**
            * @brief Public members of `BFS`
            */

            /**
             * @brief Constructor of the `BFS` class.
             */
            BFS();

            /**
             * @brief Destructor of the `BFS` class.
             */
            ~BFS();

            /**
             * @brief Solve the search problem.
             * @param start_node - start node in the environment.
             * @param goal_node - goal node in the environment.
             * @return a vector of node representing the path from the start node to the goal node.
            */
            const std::vector<std::pair<Node<T, D>, T>> solve(const Node<T, D>& start_node, const Node<T, D>& goal_node) const;
    };

} // namespace search

#endif // SEARCH_SEARCH_BFS_H