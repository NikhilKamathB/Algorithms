/**
 * @file default_cost.cpp
 * @brief Contains the implementation of the `DefaultCost` class.
 */

#include <search/cost/default_cost.h>

namespace search
{
    template <typename T, unsigned int D>
    DefaultCost<T, D>::DefaultCost(const double &default_value)
        : default_value_(default_value)
    {
        PLOGD << "Initializing DefaultCost with default value: " << default_value_;
    }

    template <typename T, unsigned int D>
    DefaultCost<T, D>::~DefaultCost()
    {
        PLOGD << "Destroying DefaultCost object";
    }

    template <typename T, unsigned int D>
    const double DefaultCost<T, D>::getCost(const Node<T, D> &from_node,
                                            const Node<T, D> &to_node) const
    {
        PLOGD << "Returning default cost from node: " << from_node.getName() << " to node: " << to_node.getName();
        return default_value_;
    }

    template <typename T, unsigned int D>
    std::ostream &operator<<(std::ostream &os, const DefaultCost<T, D> &cost)
    {
        os << "DefaultCost[DefaultValue: " << cost.default_value_ << "]";
        return os;
    }
}