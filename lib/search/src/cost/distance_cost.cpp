/**
 * @file distance_cost.cpp
 * @brief Contains the implementation of the `DistanceCost` class.
 */

#include <search/cost/distance_cost.h>

namespace search
{
    template <typename T, unsigned int D>
    DistanceCost<T, D>::DistanceCost(utils::DistanceMetric distance_metric)
        : distance_metric_(distance_metric)
    {
        PLOGD << "Initializing DistanceCost with distance metric: " << distance_metric_ << " (" << static_cast<uint8_t>(distance_metric_) << ")";
    }

    template <typename T, unsigned int D>
    DistanceCost<T, D>::~DistanceCost()
    {
        PLOGD << "Destroying DistanceCost object";
    }

    template <typename T, unsigned int D>
    const typename DistanceCost<T, D>::DistanceMetric DistanceCost<T, D>::getDistanceMetric() const
    {
        return distance_metric_;
    }

    template <typename T, unsigned int D>
    const double DistanceCost<T, D>::getCost(const Node<T, D> &from_node,
                                             const Node<T, D> &to_node) const
    {
        PLOGD << "Calculating cost from node: " << from_node.getName() << " to node: " << to_node.getName();
        switch (distance_metric_)
        {
        case utils::DistanceMetric::EUCLIDEAN:
            return (from_node.getNodeValue().value - to_node.getNodeValue().value).norm();
        case utils::DistanceMetric::MANHATTAN:
            return (from_node.getNodeValue().value - to_node.getNodeValue().value).template lpNorm<1>();
        default:
            return (from_node.getNodeValue().value - to_node.getNodeValue().value).norm();
        }
    }

} // namespace search
