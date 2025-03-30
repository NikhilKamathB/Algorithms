#ifndef SEARCH_ENVIRONMENT_ENVIRONMENT_H
#define SEARCH_ENVIRONMENT_ENVIRONMENT_H

/**
 * @file environment.h
 * @brief Abstract class for representing the environment in which the search algorithm operates.
 */

#include <plog/Log.h>
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

    public:
        /**
         * @brief Destructor for the Environment class.
         */
        virtual ~Environment() = default;

        /**
         * @brief Perform space search and return paths from start to goal.
         */
        virtual const std::vector<std::vector<std::pair<Node<T, D> *, double>>> search(
            const Node<T, D> &start_node,
            const Node<T, D> &goal_node) = 0;
    };

} // namespace search

#endif // SEARCH_ENVIRONMENT_ENVIRONMENT_H