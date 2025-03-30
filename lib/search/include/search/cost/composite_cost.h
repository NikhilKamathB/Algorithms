#ifndef SEARCH_COST_COMPOSITE_COST_H
#define SEARCH_COST_COMPOSITE_COST_H

/**
 * @file composite_cost.h
 * @brief Contains the declaration of the `CompositeCost` class. This class is used to combine multiple cost functions into a single cost function.
 */

#include <search/cost/cost.h>

namespace search
{

    /**
     * @class CompositeCost
     * @brief This class represents a composite cost function that combines multiple cost functions into one.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class CompositeCost : protected Cost<T, D>
    {
    private:
        // List of cost functions
        std::vector<const Cost<T, D> *>> cost_functions_;

        // weights for each cost function
        std::vector<double> weights_;

    public:
        /**
         * @brief Construct a new CompositeCost object.
         * @tparam C Cost function type.
         * @param cost_functions list of cost functions to combine.
         */
        template <typename... C>
            requires(std::derived_from<C, Cost<T, D>> && ...)
        CompositeCost(const C &...cost_functions);

        /**
         * @brief Construct a new CompositeCost object.
         * @tparam C Cost function type.
         * @param weights list of weights for each cost function.
         * @param cost_functions list of cost functions to combine.
         */
        template <typename... C>
            requires(std::derived_from<C, Cost<T, D>> && ...)
        CompositeCost(const std::vector<double> &weights, const C &...cost_functions);

        /**
         * @brief Destructor for the CompositeCost class.
         */
        ~CompositeCost();

        /**
         * @brief Get the const of going from node A to node B (`from_node` to `to_node`).
         * @param from_node node A.
         * @param to_node node B.
         * @return const double cost of going `from_node` to `to_node`.
         */
        const double getCost(const Node<T, D> &from_node,
                             const Node<T, D> &to_node) const override;
    };

} // namespace search

#endif // SEARCH_COST_COMPOSITE_COST_H