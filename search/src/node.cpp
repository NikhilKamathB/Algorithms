/**
 * @file node.cpp
 * @brief Contains the implementation of the `Node` class.
 */

#include <search/node.h>

namespace search
{
    template <typename T, unsigned int D>
    Node<T, D>::Node(
        const std::string &name,
        const RowVector &value,
        const DistanceMetric &distance_metric,
        const bool &use_node_value)
        : name_(name), value_(value), distance_metric_(distance_metric), use_node_value_(use_node_value) {}

    template <typename T, unsigned int D>
    Node<T, D>::~Node() {}

    template <typename T, unsigned int D>
    const bool Node<T, D>::operator==(const Node<T, D> &node) const
    {
        return (name_ == node.getName() && value_ == node.getValue());
    }

    template <typename T, unsigned int D>
    const std::string Node<T, D>::getName() const
    {
        return name_;
    }

    template <typename T, unsigned int D>
    void Node<T, D>::setName(const std::string &name)
    {
        name_ = name;
    }

    template <typename T, unsigned int D>
    const typename Node<T, D>::RowVector Node<T, D>::getValue() const
    {
        return value_;
    }

    template <typename T, unsigned int D>
    void Node<T, D>::setValue(const RowVector &value)
    {
        value_ = value;
    }

    template <typename T, unsigned int D>
    const DistanceMetric Node<T, D>::getDistanceMetric() const
    {
        return distance_metric_;
    }

    template <typename T, unsigned int D>
    const T Node<T, D>::getDistance(const Node<T, D> &next_node) const
    {
        switch (distance_metric_)
        {
        case DistanceMetric::EUCLIDEAN:
            return (value_ - next_node.getValue()).norm();
        case DistanceMetric::MANHATTAN:
            return (value_ - next_node.getValue()).template lpNorm<1>();
        default:
            return (value_ - next_node.getValue()).norm();
        }
    }

    template <typename T, unsigned int D>
    const T Node<T, D>::getCost(const Node<T, D> &next_node) const
    {
        return this->getDistance(next_node);
    }

    template <typename T, unsigned int D>
    const T Node<T, D>::getHeuristicCost(const Node<T, D> &goal_node) const
    {
        return this->getDistance(goal_node);
    }

    template <typename T, unsigned int D>
    void Node<T, D>::addNeighbor(const Node<T, D> &neighbor)
    {
        neighbors_.push_back(&neighbor);
    }

    template <typename T, unsigned int D>
    const std::vector<const Node<T, D> *> Node<T, D>::getNeighbors() const
    {
        return neighbors_;
    }

    template <typename T, unsigned int D>
    bool NodeFnComparator<T, D>::operator()(const std::pair<const Node<T, D> *, T> &lhs, const std::pair<const Node<T, D> *, T> &rhs) const
    {
        return lhs.second > rhs.second;
    }

    // Explicit instantiation of the template class.
    template class Node<float, 1U>;
    template class Node<float, 2U>;
    template class Node<float, 3U>;
    template class Node<double, 1U>;
    template class Node<double, 2U>;
    template class Node<double, 3U>;
    template class NodeFnComparator<float, 1U>;
    template class NodeFnComparator<float, 2U>;
    template class NodeFnComparator<float, 3U>;
    template class NodeFnComparator<double, 1U>;
    template class NodeFnComparator<double, 2U>;
    template class NodeFnComparator<double, 3U>;

} // namespace search