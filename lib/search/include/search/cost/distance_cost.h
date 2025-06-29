#ifndef SEARCH_COST_DISTANCE_COST_H
#define SEARCH_COST_DISTANCE_COST_H

/**
 * @file distance_cost.h
 * @brief Computes distance-based costs between nodes in a search space.
 */

#include <plog/Log.h>
#include <utils/constants.h>
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
    class DistanceCost : public Cost<T, D>
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
        DistanceCost(DistanceMetric distance_metric = DistanceMetric::EUCLIDEAN)
            : distance_metric_(distance_metric)
        {
            PLOGD << "Initializing DistanceCost with distance metric: " << distance_metric_ << " (" << static_cast<uint8_t>(distance_metric_) << ")";
        }

        /**
         * @brief Destroy the DistanceCost object.
         */
        ~DistanceCost()
        {
            PLOGD << "Destroying DistanceCost object";
        }

        /**
         * @brief Get the distance metric used to calculate the cost.
         * @return const DistanceMetric distance metric item.
         */
        const DistanceMetric get_distance_metric() const
        {
            return distance_metric_;
        }

        /**
         * @brief Get the cost of going from node A to node B (`from_node` to `to_node`).
         * The cost is calculated using the distance metrics.
         * @param from_node node A.
         * @param to_node node B.
         * @return const double cost of going `from_node` to `to_node`.
         */
        const double get_cost(const Node<T, D> &from_node,
                              const Node<T, D> &to_node) const override
        {
            PLOGD << "Calculating distance based cost from node: " << from_node.get_name() << " to node: " << to_node.get_name();
            switch (distance_metric_)
            {
            case DistanceMetric::EUCLIDEAN:
                PLOGD << "Using Euclidean distance metric";
                return (from_node.getNodeValue().value - to_node.getNodeValue().value).norm();
            case DistanceMetric::MANHATTAN:
                PLOGD << "Using Manhattan distance metric";
                return (from_node.getNodeValue().value - to_node.getNodeValue().value).template lpNorm<1>();
            default:
                PLOGE << "Unknown distance metric: " << static_cast<uint8_t>(distance_metric_);
                throw std::invalid_argument("Unknown distance metric");
            }
        }

        /**
         * @brief << operator - function for streaming the DistanceCost to an output stream.
         * @param os output stream.
         * @param cost cost to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const DistanceCost<T, D> &cost)
        {
            os << "DistanceCost[DistanceMetric: " << static_cast<uint8_t>(cost.getDistanceMetric()) << "]";
        }
    };

} // namespace search

#endif // SEARCH_COST_DISTANCE_COST_H