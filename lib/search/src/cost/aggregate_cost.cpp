/**
 * @file aggregate_cost.cpp
 * @brief Contains the implementation of the `AggregateCost` class.
 */

#include <search/cost/aggregate_cost.h>

namespace search
{
    template <typename T, unsigned int D>
    template <typename... C>
        requires(std::derived_from<C, Cost<T, D>> && ...)
    AggregateCost<T, D>::AggregateCost(const C &...cost_functions)
        : cost_functions_{&cost_functions...}
    {
        PLOGD << "Initializing aggregateCost with " << sizeof...(cost_functions) << " cost functions and equally distributed weights";
        weights_.resize(cost_functions_.size(), 1.0);
    }

    template <typename T, unsigned int D>
    template <typename... C>
        requires(std::derived_from<C, Cost<T, D>> && ...)
    AggregateCost<T, D>::AggregateCost(const std::vector<double> &weights, const C &...cost_functions)
        : weights_(weights),
          cost_functions_{&cost_functions...}
    {
        PLOGD << "Initializing aggregateCost with " << sizeof...(cost_functions) << " cost functions and " << weights.size() << " weights";
        if (weights_.size() != cost_functions_.size())
        {
            PLOGE << "Weights size does not match the number of cost functions passed";
            throw std::invalid_argument("Weights size must match the number of cost functions passed");
        }
    }

    template <typename T, unsigned int D>
    AggregateCost<T, D>::~AggregateCost()
    {
        PLOGD << "Destroying AggregateCost object";
    }

    template <typename T, unsigned int D>
    const double AggregateCost<T, D>::getCost(const Node<T, D> &from_node,
                                              const Node<T, D> &to_node) const
    {
        PLOGD << "Computing cost from node " << from_node.getName() << " to node " << to_node.getName();
        double total_cost = 0.0;
        for (std::size_t idx = 0; idx < cost_functions_.size(); ++idx)
        {
            total_cost += weights_[idx] * cost_functions_[idx]->getCost(from_node, to_node);
        }
        return total_cost;
    }

    template <typename T, unsigned int D>
    std::ostream &operator<<(std::ostream &os, const AggregateCost<T, D> &cost) {
        os << "AggregateCost[";
        std::vector<const Cost<T, D> *> cost_functions_;
        for (const Cost<T, D> *cost_function : cost_functions_)
        {
            os << *cost_function << ", ";
        }
        os << "]";
        return os;
    }

} // namespace search
