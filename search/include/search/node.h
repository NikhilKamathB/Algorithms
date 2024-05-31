#ifndef SEARCH_NODE_H
#define SEARCH_NODE_H

/**
 * @file node.h
 * @brief Contains the definition of the `Node` class.
 */

#include <search/utils.h>

namespace search
{
    /**
     * @class Node
     * @brief This class represents a node in the search space.
     * @details An instance of the `Node` class represents a node in the search space.
     * The `Node` class takes in a templated type `T` and dimensions `D` as arguments:
     * `value` - the value of the node, this may be one, two or three dinmensional.
     */
    template <typename T, unsigned int D>
    class Node
    {
        using RowVector = Eigen::Matrix<T, 1, D>;

    private:
        /**
         * @brief Private members of `Node`
         */

        // Name of the node.
        std::string name_;

        // Value of the node.
        RowVector value_;

        // Distance metric used to compute the cost.
        DistanceMetric distance_metric_;

        // Flag to use the node value or not for computing the cost.
        bool use_node_value_;

        // Neighboring nodes.
        std::vector<const Node<T, D> *> neighbors_;

    public:
        /**
         * @brief Public members of `Node`
         */

        /**
         * @brief Constructor of the `Node` class.
         * @param name - name of the node, default is an empty string.
         * @param value - value of the node, default is null.
         * @param distance_metric - distance metric used to compute the cost.
         * @param use_node_value - flag to use the node value or not for computing the cost.
         */
        Node(const std::string &name = "",
             const RowVector &value = RowVector::Zero(),
             const DistanceMetric &distance_metric = DistanceMetric::EUCLIDEAN,
             const bool &use_node_value = true);

        /**
         * @brief Destructor of the `Node` class.
         */
        ~Node();

        /**
         * @brief Checks whether *this is equal to the other node (on rhs).
         * @param rhs - other node to compare with.
         * @return bool - true if *this is equal to the other node, false otherwise.
         */
        const bool operator==(const Node<T, D> &rhs) const;

        /**
         * @brief Get the name of the node.
         * @return name of the node.
         */
        const std::string getName() const;

        /**
         * @brief Set the name of the node.
         * @param name - name of the node.
         */
        void setName(const std::string &name);

        /**
         * @brief Get the value of the node.
         * @return value of the node.
         */
        const RowVector getValue() const;

        /**
         * @brief Set the value of the node.
         * @param value - value of the node.
         */
        void setValue(const RowVector &value);

        /**
         * @brief Get the distance metric used to compute the cost.
         * @return DistanceMetric - distance metric used to compute the cost.
         */
        const DistanceMetric getDistanceMetric() const;

        /**
         * @brief Get the distance between this node and the next neighboring node.
         * @param next_node - next neighboring node.
         * @return T - distance between this node and the next neighboring node.
         */
        const T getDistance(const Node<T, D> &next_node) const;

        /**
         * @brief Get/Compute the cost of the path from this node to the next neighboring node.
         * @param next_node - next neighboring node.
         */
        const T getCost(const Node<T, D> &next_node) const;

        /**
         * @brief Add a neighbor to the node.
         * @param neighbor - neighbor to add to the node.
         */
        void addNeighbor(const Node<T, D> &neighbor);

        /**
         * @brief Get the neighbors of the node.
         * @return std::vector<Node<T, D>> - neighbors of the node.
         */
        const std::vector<const Node<T, D> *> getNeighbors() const;
    };

    /**
     * @struct NodeGnCompator
     * @brief This struct represents a comparator for the `Node` class.
     * @details This struct will enable comparison of two nodes based on their `g(n)` values.
     */
    template <typename T, unsigned int D>
    struct NodeGnComparator
    {
        /**
         * @brief Comparator for two nodes based on their `g(n)` values.
         * @param lhs - left hand side node.
         * @param rhs - right hand side node.
         * @return bool - true if `g(n)` of lhs is greater than `g(n)` of rhs, false otherwise.
         */
        bool operator()(const std::pair<const Node<T, D> *, T> &lhs, const std::pair<const Node<T, D> *, T> &rhs) const;
    };
} // namespace search

#endif // SEARCH_NODE_H