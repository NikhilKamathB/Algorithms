#ifndef SEARCH_COST_DISTANCE_COST_H
#define SEARCH_COST_DISTANCE_COST_H

/**
 * @file distance_cost.h
 * @brief Contains the declaration of the `DistanceCost` class. Entends the `Cost` class by calculating the distance between two nodes.
 */

#include <search/cost/cost.h>

namespace search
{

    /**
     * @class DistanceCost
     * @brief Represents the cost of taking an action from this node to another node in the search space and it is calculated using various distance metrics.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class DistanceCost : protected Cost<T, D>
    {

        using DistanceMetric = utils::DistanceMetric;

    private:
        // Distance value
        double distance_value_;

        // Distance metric
        DistanceMetric distance_metric_;

    public:
        /**
         * @brief Construct a new DistanceCost object.
         * @param distance_value distance value.
         */
        DistanceCost(DistanceMetric distance_metric = DistanceMetric::EUCLIDEAN);

        /**
         * @brief Destroy the DistanceCost object.
         */
        ~DistanceCost();

        /**
         * @brief Get the distance metric used to calculate the cost.
         * @return const DistanceMetric distance metric item.
         */
        const DistanceMetric getDistanceMetric() const;

        /**
         * @brief Get the const of going from node A to node B (`from_node` to `to_node`).
         * The cost is calculated using the distance metrics.
         * @param from_node node A.
         * @param to_node node B.
         * @return const double cost of going `from_node` to `to_node`.
         */
        const double getCost(const Node<T, D> &from_node,
                             const Node<T, D> &to_node) const override;
    };

} // namespace search

#endif // SEARCH_COST_DISTANCE_COST_H