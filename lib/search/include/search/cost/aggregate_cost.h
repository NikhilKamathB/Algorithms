#ifndef SEARCH_COST_AGGREGATE_COST_H
#define SEARCH_COST_AGGREGATE_COST_H

/**
 * @file aggregate_cost.h
 * @brief Contains the declaration of the `AggregateCost` class. This class is used to combine multiple cost functions into a single cost function.
 */

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
    class AggregateCost : protected Cost<T, D>
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
        AggregateCost(const C &...cost_functions);

        /**
         * @brief Construct a new AggregateCost object.
         * @tparam C Cost function type.
         * @param weights list of weights for each cost function.
         * @param cost_functions list of cost functions to combine.
         */
        template <typename... C>
            requires(std::derived_from<C, Cost<T, D>> && ...)
        AggregateCost(const std::vector<double> &weights, const C &...cost_functions);

        /**
         * @brief Destructor for the AggregateCost class.
         */
        ~AggregateCost();

        /**
         * @brief Get the const of going from node A to node B (`from_node` to `to_node`).
         * @param from_node node A.
         * @param to_node node B.
         * @return const double cost of going `from_node` to `to_node`.
         */
        const double getCost(const Node<T, D> &from_node,
                             const Node<T, D> &to_node) const override;

        /**
         * @brief << operator - function for streaming the AggregateCost to an output stream.
         * @param os output stream.
         * @param cost cost to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const AggregateCost<T, D> &cost);
    };

} // namespace search

#endif // SEARCH_COST_AGGREGATE_COST_H