#ifndef SEARCH_NODE_NODE_H
#define SEARCH_NODE_NODE_H

/**
 * @file node.h
 * @brief Contains the declaration of the `Node` type.
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
        friend std::ostream &operator<<(std::ostream &os, const NodeValue<T, D> &node_value);
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
        std::vector<Node<T, D> *> neighbors_;

        // UUID generator
        static boost::uuids::random_generator uuid_generator_;

    public:
        /**
         * @brief Construct a new Node object.
         * @param value value of the node.
         * @param name name of the node - default is an empty string.
         */
        Node(const NodeValue<T, D> &node_value,
             const std::string &name = "");

        /**
         * @brief Destroy the Node object.
         */
        ~Node();

        /**
         * @brief Get the name of the node.
         * @return const std::string& name of the node.
         */
        const std::string &getName() const;

        /**
         * @brief Get neighbors of the node.
         * @return const std::vector<Node<T, D>*>& neighbors of the node.
         */
        const std::vector<Node<T, D> *> &getNeighbors() const;

        /**
         * @brief Get the value of the node.
         * @return const NodeValue<T, D>& value of the node.
         */
        const NodeValue<T, D> &getNodeValue() const;

        /**
         * @brief Add a neighbor to the node.
         * @param neighbor neighbor to add.
         */
        void addNeighbor(const Node<T, D> &neighbor);

        /**
         * @brief Set the name of the node.
         * @param name name of the node.
         */
        void setName(const std::string &name);

        /**
         * @brief << operator - a friend function for streaming the Node to an output stream.
         * @param os output stream.
         * @param node node to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const Node<T, D> &node);

        /**
         * @brief == operator - a friend function overload for comparing two nodes.
         * @param lhs left hand side node.
         * @param rhs right hand side node.
         * @return true if the nodes are equal, false otherwise.
         */
        friend const bool operator==(const Node<T, D> &lhs, const Node<T, D> &rhs);
    };

} // namespace search

#endif // SEARCH_NODE_NODE_H