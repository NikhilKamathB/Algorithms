/**
 * @file node.cpp
 * @brief Contains the implementation of the `Node` class.
*/

#include <node.h>

namespace search
{   
    template <typename T, unsigned int D>
    Node<T, D>::Node(
        const std::string& name,  
        const DistanceMetric& distance_metric,
        const bool& use_node_value,
        const RowVector& value)
        :name_(name), value_(value), use_node_value_(use_node_value){}

    template <typename T, unsigned int D>
    Node<T, D>::~Node(){}

    template <typename T, unsigned int D>
    const std::string Node<T, D>::getName() const
    {
        return name_;
    }

    template <typename T, unsigned int D>
    void Node<T, D>::setName(const std::string& name)
    {
        name_ = name;
    }

    template <typename T, unsigned int D>
    const typename Node<T, D>::RowVector Node<T, D>::getValue() const
    {
        return value_;
    }

    template <typename T, unsigned int D>
    void Node<T, D>::setValue(const RowVector& value)
    {
        value_ = value;
    }

    template <typename T, unsigned int D>
    const DistanceMetric Node<T, D>::getDistanceMetric() const
    {
        return distance_metric_;
    }

    template <typename T, unsigned int D>
    const T Node<T, D>::getDistance(Node<T, D>& next_node) const
    {
        switch (distance_metric_)
        {
            case DistanceMetric::EUCLIDEAN:
                return (value_ - next_node.getValue()).norm();
            case DistanceMetric::MANHATTAN:
                return (value_ - next_node.getValue()).lpNorm<1>();
            default:
                return (value_ - next_node.getValue()).norm();
        }
    }

    template <typename T, unsigned int D>
    void Node<T, D>::computeCost(Node<T, D>& next_node)
    {
        T distance_cost = this->getDistance(next_node);
        this->cost_ = distance_cost;
    }

    template <typename T, unsigned int D>
    const T Node<T, D>::getCost() const
    {
        return cost_;
    }

    // Explicit instantiation of the template class.
    template class Node<float, 1U>;
    template class Node<float, 2U>;
    template class Node<float, 3U>;
    template class Node<double, 1U>;
    template class Node<double, 2U>;
    template class Node<double, 3U>;
} // namespace search