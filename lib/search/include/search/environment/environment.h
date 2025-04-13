#ifndef SEARCH_ENVIRONMENT_ENVIRONMENT_H
#define SEARCH_ENVIRONMENT_ENVIRONMENT_H

/**
 * @file environment.h
 * @brief Abstract class for representing the environment in which the search algorithm operates.
 */

#include <plog/Log.h>
#include <utils/constants.h>
#include <search/cost/cost.h>
#include <search/node/node.h>

namespace search
{

    /**
     * @class Environment
     * @brief Abstract class for representing the environment in which the search algorithm operates. Extends the `Environment` class to define a custom environment.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class Environment
    {

        using SearchAlgorithm = utils::SearchAlgorithm;

    public:
        /**
         * @brief Destructor for the Environment class.
         */
        virtual ~Environment() = default;

        /**
         * @brief Initialize the environment.
         */
        virtual void initialize() = 0;

        /**
         * @brief Perform space search and return paths from start to goal.
         * @param start_node The starting node.
         * @param goal_node The goal node.
         * @param search_algorithm The search algorithm to use (DFS, BFS, UCS, A_STAR) - default is DFS.
         * @return A vector of vectors of pairs representing the paths from start to goal along with their step costs.
         */
        virtual const std::vector<std::vector<std::pair<const Node<T, D> *, double>>> search(
            const Node<T, D> &start_node,
            const Node<T, D> &goal_node,
            SearchAlgorithm search_algorithm = SearchAlgorithm::DFS) const = 0;
    };

} // namespace search

#endif // SEARCH_ENVIRONMENT_ENVIRONMENT_H