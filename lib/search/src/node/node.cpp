/**
 * @file node.cpp
 * @brief Contains the implementation of the `Node` class.
 */

#include <search/node/node.h>

namespace search
{
    template <typename T, unsigned int D>
    boost::uuids::random_generator Node<T, D>::uuid_generator_;

    template <typename T, unsigned int D>
    Node<T, D>::Node(const NodeValue<T, D> &node_value, const std::string &name)
        : node_value_(node_value),
          name_(name),
          uuid_(uuid_generator_())
    {
        PLOGD << "Initializing Node object: " << name_ << " with UUID: " << uuid_;
    }

    template <typename T, unsigned int D>
    Node<T, D>::~Node()
    {
        PLOGD << "Destroying Node object: " << name_;
    }

    template <typename T, unsigned int D>
    const std::string &Node<T, D>::getName() const
    {
        return name_;
    }

    template <typename T, unsigned int D>
    const std::vector<const Node<T, D> *> &Node<T, D>::getNeighbors() const
    {
        return neighbors_;
    }

    template <typename T, unsigned int D>
    const NodeValue<T, D> &Node<T, D>::getNodeValue() const
    {
        return node_value_;
    }

    template <typename T, unsigned int D>
    void Node<T, D>::addNeighbor(const Node<T, D> &neighbor)
    {
        neighbors_.emplace_back(&neighbor);
    }

    template <typename T, unsigned int D>
    void Node<T, D>::addNeighbor(const Node<T, D> *neighbor)
    {
        if (neighbor != nullptr)
        {
            neighbors_.emplace_back(neighbor);
        }
        else
        {
            PLOGW << "Attempted to add a null neighbor to node: " << name_ << " - skipping.";
        }
    }

    template <typename T, unsigned int D>
    void Node<T, D>::setName(const std::string &name)
    {
        name_ = name;
    }

    template <typename T, unsigned int D>
    std::ostream &operator<<(std::ostream &os, const typename Node<T, D>::NodeValue &node_value)
    {
        os << "NodeValue: " << node_value.value;
        return os;
    }

    template <typename T, unsigned int D>
    std::ostream &operator<<(std::ostream &os, const Node<T, D> &node)
    {
        os << "Node[" << node.name_ << "]: ";
        os << node.node_value_ << std::endl;
        os << "Neighbors[";
        for (const Node<T, D> *neighbor : node.neighbors_)
        {
            os << neighbor->name_ << ", ";
        }
        os << "]" << std::endl;
        return os;
    }

    template <typename T, unsigned int D>
    const bool operator==(const Node<T, D> &lhs, const Node<T, D> &rhs)
    {
        return lhs.uuid_ == rhs.uuid_;
    }

} // namespace search