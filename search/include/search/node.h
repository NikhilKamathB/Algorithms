#ifndef SEARCH_NODE_H
#define SEARCH_NODE_H

/**
 * @file node.h
 * @brief Contains the definition of the `Node` class.
 */

#include <utils.h>
#include <Eigen/Dense>

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

            // Cost of the path from previous node to the current node.
            T cost_;

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
            Node(const std::string& name = "",
                 const DistanceMetric& distance_metric = DistanceMetric::EUCLIDEAN,
                 const bool& use_node_value = true, 
                 const RowVector &value = RowVector::Zero());

            /**
             * @brief Destructor of the `Node` class.
            */
            ~Node();

            /**
             * @brief Get the name of the node.
             * @return name of the node.
            */
            const std::string getName() const;

            /**
             * @brief Set the name of the node.
             * @param name - name of the node.
            */
            void setName(const std::string& name);

            /**
             * @brief Get the value of the node.
             * @return value of the node.
            */
            const RowVector getValue() const;

            /**
             * @brief Set the value of the node.
             * @param value - value of the node.
            */
            void setValue(const RowVector& value);

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
            const T getDistance(Node<T, D>& next_node) const;

            /**
             * @brief Compute the cost of the path from this node to the next neighboring node.
             * @param next_node - next neighboring node.
             */
            void computeCost(Node<T, D> &next_node);

            /**
             * @brief Get the cost of the path from this node to the next neighboring node.
             * @return T - cost of the path from this node to the next neighboring node.
             */
            const T getCost() const;
    };
    
} // namespace search


#endif // SEARCH_NODE_H