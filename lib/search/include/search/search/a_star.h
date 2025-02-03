#ifndef SEARCH_SEARCH_A_STAR_H
#define SEARCH_SEARCH_A_STAR_H

/**
 * @file a_star.h
 * @brief Contains the definition of the `AStar` class/implementation.
 */

#include <search/search/base.h>

namespace search
{

    /**
     * @class AStar
     * @brief This class represents the A* search algorithm.
     * @details An instance of the `AStar` class represents the A* search algorithm.
     */

    template <typename T, unsigned int D>
    class AStar : public SearchBase<T, D>
    {

    private:
        /**
         * @brief Private members of `AStar`
         */

    public:
        /**
         * @brief Public members of `AStar`
         */

        /**
         * @brief Constructor of the `AStar` class.
         */
        AStar();

        /**
         * @brief Destructor of the `AStar` class.
         */
        ~AStar();

        /**
         * @brief Solve the search problem.
         * @param start_node - start node in the environment.
         * @param goal_node - goal node in the environment.
         * @return a vector of node and their cumulative costs representing the path from the start node to the goal node.
         */
        const std::vector<std::pair<Node<T, D>, T>> solve(const Node<T, D> &start_node, const Node<T, D> &goal_node) const;
    };

} // namespace search

#endif // SEARCH_SEARCH_A_STAR_H