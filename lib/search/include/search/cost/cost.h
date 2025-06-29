#ifndef SEARCH_COST_COST_H
#define SEARCH_COST_COST_H

/**
 * @file cost.h
 * @brief Abstract class for representing the cost of taking an action from this node to another. This is mostly a pure virtual class and must be inherited to define a custom cost.
 */

#include <search/node/node.h>

namespace search
{

    /**
     * @class Cost
     * @brief Abstract class for representing the cost of a node. Extends the `Cost` class to define a custom cost.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class Cost
    {

    public:
        /**
         * @brief Construct a new Cost object.
         */
        Cost() = default;
        
        /**
         * Destructor for the Cost class.
         */
        virtual ~Cost() = default;
        
        /**
         * @brief Get the const of going from node A to node B (`from_node` to `to_node`).
         * @param from_node node A.
         * @param to_node node B.
         * @return const double cost of going `from_node` to `to_node`.
         */
        virtual const double get_cost(const Node<T, D> &from_node,
                                     const Node<T, D> &to_node) const = 0;
    };

} // namespace search

#endif // SEARCH_COST_COST_H