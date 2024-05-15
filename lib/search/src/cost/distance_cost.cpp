/**
 * @file distance_cost.cpp
 * @brief Contains the implementation of the `DistanceCost` class.
 */

#include <search/cost/distance_cost.h>

namespace search
{
    template <typename T, unsigned int D>
    DistanceCost<T, D>::DistanceCost(utils::DistanceMetric distance_metric)
        : distance_metric_(distance_metric) {}

    template <typename T, unsigned int D>
    DistanceCost<T, D>::~DistanceCost() {}

    template <typename T, unsigned int D>
    const double DistanceCost<T, D>::getCost(const Node<T, D> &from_node,
                                              const Node<T, D> &to_node) const
    {
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
