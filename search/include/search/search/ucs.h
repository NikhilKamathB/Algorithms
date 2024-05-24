#ifndef SEARCH_SEARCH_UCS_H
#define SEARCH_SEARCH_UCS_H

/**
 * @file ucs.h
 * @brief Contains the definition of the `UCS` class/implementation.
*/

#include <search/search/base.h>

namespace search {

    /**
     * @class UCS
     * @brief This class represents the Uniform Cost Search algorithm.
     * @details An instance of the `UCS` class represents the Uniform Cost Search algorithm.
    */

    template <typename T, unsigned int D>
    class UCS: public SearchBase<T, D> {
    
         private:
            /**
            * @brief Private members of `UCS`
            */
    
         public:
            /**
            * @brief Public members of `UCS`
            */

            /**
             * @brief Constructor of the `UCS` class.
            */
            UCS();

            /**
             * @brief Destructor of the `UCS` class.
            */
            ~UCS();

            /**
             * @brief Solve the search problem.
             * @param start_node - start node in the environment.
             * @param goal_node - goal node in the environment.
             * @return a vector of node and their cumulative costs representing the path from the start node to the goal node.
            */
            const std::vector<std::pair<Node<T, D>, T>> solve(const Node<T, D>& start_node, const Node<T, D>& goal_node) const;
    };

} // namespace search

#endif // SEARCH_SEARCH_UCS_H