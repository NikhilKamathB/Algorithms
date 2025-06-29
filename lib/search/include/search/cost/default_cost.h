#ifndef SEARCH_COST_DEFAULT_COST_H
#define SEARCH_COST_DEFAULT_COST_H

/**
 * @file default_cost.h
 * @brief Use default cost class to induce a constant cost for all actions in the search space.
 */

#include <plog/Log.h>
#include <search/cost/cost.h>

namespace search
{

    /**
     * @class DefaultCost
     * @brief Represents the default cost of taking an action from this node to another node in the search space.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class DefaultCost : public Cost<T, D>
    {

    private:
        // Default value
        double default_value_;

    public:
        /**
         * @brief Construct a new DefaultCost object.
         * @param default_value_ default value.
         */
        DefaultCost(const double default_value = 1.0)
            : default_value_(default_value)
        {
            PLOGD << "Initializing DefaultCost with default value: " << default_value_;
        }

        /**
         * @brief Destroy the DefaultCost object.
         */
        ~DefaultCost()
        {
            PLOGD << "Destroying DefaultCost object";
        }

        /**
         * @brief Get the default cost of going from node A to node B (`from_node` to `to_node`).
         * @param from_node node A.
         * @param to_node node B.
         * @return const default double cost of going `from_node` to `to_node`.
         */
        const double get_cost(const Node<T, D> &from_node,
                              const Node<T, D> &to_node) const override
        {
            PLOGD << "Returning default cost from node: " << from_node.get_name() << " to node: " << to_node.get_name();
            return default_value_;
        }

        /**
         * @brief << operator - function for streaming the DefaultCost to an output stream.
         * @param os output stream.
         * @param cost cost to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const DefaultCost<T, D> &cost)
        {
            os << "DefaultCost[DefaultValue: " << cost.default_value_ << "]";
            return os;
        }
    };

} // namespace search

#endif // SEARCH_COST_DEFAULT_COST_H