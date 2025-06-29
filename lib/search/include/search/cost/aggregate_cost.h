#ifndef SEARCH_COST_AGGREGATE_COST_H
#define SEARCH_COST_AGGREGATE_COST_H

/**
 * @file aggregate_cost.h
 * @brief This class aggregates multiple cost functions into one.
 */

#include <plog/Log.h>
#include <search/cost/cost.h>

namespace search
{

    /**
     * @class AggregateCost
     * @brief This class represents a aggregate cost function that combines multiple cost functions into one.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class AggregateCost : public Cost<T, D>
    {

    private:
        // List of cost functions
        std::vector<const Cost<T, D> *> cost_functions_;

        // weights for each cost function
        std::vector<double> weights_;

    public:
        /**
         * @brief Construct a new AggregateCost object.
         * @tparam C Cost function type.
         * @param cost_functions list of cost functions to combine.
         */
        template <typename... C>
            requires(std::derived_from<C, Cost<T, D>> && ...)
        AggregateCost(const C &...cost_functions)
            : cost_functions_{&cost_functions...}
        {
            PLOGD << "Initializing aggregateCost with " << sizeof...(cost_functions) << " cost functions and equally distributed weights";
            weights_.resize(cost_functions_.size(), 1.0);
        }

        /**
         * @brief Construct a new AggregateCost object.
         * @tparam C Cost function type.
         * @param weights list of weights for each cost function.
         * @param cost_functions list of cost functions to combine.
         */
        template <typename... C>
            requires(std::derived_from<C, Cost<T, D>> && ...)
        AggregateCost(const std::vector<double> &weights, const C &...cost_functions)
        {
            PLOGD << "Initializing aggregateCost with " << sizeof...(cost_functions) << " cost functions and " << weights.size() << " weights";
            if (weights.size() != sizeof...(cost_functions))
            {
                PLOGE << "Weights size does not match the number of cost functions passed";
                throw std::invalid_argument("Weights size must match the number of cost functions passed");
            }
            weights_ = weights;
            cost_functions_ = {&cost_functions...};
        }

        /**
         * @brief Destructor for the AggregateCost class.
         */
        ~AggregateCost()
        {
            PLOGD << "Destroying AggregateCost object";
        }

        /**
         * @brief Get the const of going from node A to node B (`from_node` to `to_node`).
         * @param from_node node A.
         * @param to_node node B.
         * @return const double cost of going `from_node` to `to_node`.
         */
        const double get_cost(const Node<T, D> &from_node,
                              const Node<T, D> &to_node) const override
        {
            PLOGD << "Computing aggregate cost from node " << from_node.get_name() << " to node " << to_node.get_name();
            double total_cost = 0.0;
            for (std::size_t idx = 0; idx < cost_functions_.size(); ++idx)
            {
                total_cost += weights_[idx] * cost_functions_[idx]->get_cost(from_node, to_node);
            }
            return total_cost;
        }

        /**
         * @brief << operator - function for streaming the AggregateCost to an output stream.
         * @param os output stream.
         * @param cost cost to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const AggregateCost<T, D> &cost)
        {
            os << "AggregateCost[";
            std::vector<const Cost<T, D> *> cost_functions_;
            for (const Cost<T, D> *cost_function : cost_functions_)
            {
                os << *cost_function << ", ";
            }
            os << "]";
            return os;
        }
    };

} // namespace search

#endif // SEARCH_COST_AGGREGATE_COST_H