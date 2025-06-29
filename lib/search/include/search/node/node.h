#ifndef SEARCH_NODE_NODE_H
#define SEARCH_NODE_NODE_H

/**
 * @file node.h
 * @brief Contains the base node class entity in the state space search.
 */

#include <plog/Log.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <math/types.h>

namespace search
{

    /**
     * @struct NodeValue
     * @brief This struct represents the value of a node. Extends the `NodeValue` struct to define a custom node value.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    struct NodeValue
    {

        using ColumnVector = math::ColumnVector<T, D>;

        // Node value
        ColumnVector value;

        /**
         * @brief << operator - a friend function for streaming the NodeValue to an output stream.
         * @param os output stream.
         * @param node_value node value to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const NodeValue<T, D> &node_value)
        {
            os << "NodeValue: " << node_value.value;
            return os;
        }
    };

    /**
     * @class Node
     * @brief This class represents a node in a graph / search space (a basic node). Inherit from this class to create a custom node.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class Node
    {

    private:
        // Node uuid
        boost::uuids::uuid uuid_;

        // Node name
        std::string name_;

        // Node value
        NodeValue<T, D> node_value_;

        // Node neighbors
        std::vector<const Node<T, D> *> neighbors_;

        // UUID generator
        inline static boost::uuids::random_generator uuid_generator_;

    public:
        /**
         * @brief Construct a new Node object.
         * @param value value of the node.
         * @param name name of the node - default is an empty string.
         */
        Node(const NodeValue<T, D> &node_value,
             const std::string &name = "")
            : uuid_(uuid_generator_()),
              node_value_(node_value)
        {
            if (name.empty())
            {
                name_ = boost::uuids::to_string(uuid_);
            }
            else
            {
                name_ = name;
            }
            PLOGD << "Initializing Node object with name: " << name_;
        }

        /**
         * @brief Destroy the Node object.
         */
        ~Node()
        {
            PLOGD << "Destroying Node object: " << name_;
        }

        /**
         * @brief Get the name of the node.
         * @return const std::string& name of the node.
         */
        const std::string &get_name() const
        {
            return name_;
        }

        /**
         * @brief Get neighbors of the node.
         * @return const std::vector<Node<T, D>*>& neighbors of the node.
         */
        const std::vector<const Node<T, D> *> &get_neighbors() const
        {
            return neighbors_;
        }

        /**
         * @brief Get the value of the node.
         * @return const NodeValue<T, D>& value of the node.
         */
        const NodeValue<T, D> &get_node_value() const
        {
            return node_value_;
        }

        /**
         * @brief Add a neighbor to the node.
         * @param neighbor neighbor to add - a reference to a Node object.
         */
        void add_neighbor(const Node<T, D> &neighbor)
        {
            neighbors_.emplace_back(&neighbor);
        }

        /**
         * @brief Add a neighbor to the node.
         * @param neighbor neighbor to add - a pointer to a Node object.
         */
        void add_neighbor(const Node<T, D> *neighbor)
        {
            if (neighbor != nullptr)
            {
                neighbors_.emplace_back(neighbor);
            }
            else
            {
                PLOGW << "Attempted to add a null neighbor to node: " << name_ << " - skipping";
            }
        }

        /**
         * @brief Set the name of the node.
         * @param name name of the node.
         */
        void set_name(const std::string &name)
        {
            name_ = name;
        }

        /**
         * @brief << operator - a friend function for streaming the Node to an output stream.
         * @param os output stream.
         * @param node node to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const Node<T, D> &node)
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

        /**
         * @brief == operator - a friend function overload for comparing two nodes.
         * @param lhs left hand side node.
         * @param rhs right hand side node.
         * @return true if the nodes are equal, false otherwise.
         */
        friend const bool operator==(const Node<T, D> &lhs, const Node<T, D> &rhs)
        {
            return lhs.uuid_ == rhs.uuid_;
        }

        /**
         * @brief != operator - a friend function overload for comparing two nodes.
         * @param lhs left hand side node.
         * @param rhs right hand side node.
         * @return true if the nodes are not equal, false otherwise.
         */
        friend const bool operator!=(const Node<T, D> &lhs, const Node<T, D> &rhs)
        {
            return !(lhs == rhs);
        }
    };

} // namespace search

#endif // SEARCH_NODE_NODE_H