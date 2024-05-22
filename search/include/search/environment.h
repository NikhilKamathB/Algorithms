#ifndef SEARCH_ENVIRONMENT_H
#define SEARCH_ENVIRONMENT_H

/**
 * @file environment.h
 * @brief Contains the definition of the `Environment` class.
 */

#include <search/node.h>

namespace search
{
    /**
     * @class Environment
     * @brief This class represents the environment in which the search is performed.
     * @details An instance of the `Environment` class represents the environment in which the search is performed.
     * It contains a bunch of nodes and the connections between them.
     * Bottom line, the `Environment` class is a graph and contains all the information needed to perform a search.
    */
    template <typename T, unsigned int D>
    class Environment
    {
        using RowVector = Eigen::Matrix<T, 1, D>;

        private:
            /**
             * @brief Private members of `Environment`
             */

            // Number of nodes in the environment.
            std::size_t num_nodes_;

            // Edges between the nodes in the environment.
            std::vector<std::pair<std::size_t, std::size_t>> edges_;

            // Distance metric used to compute the cost.
            DistanceMetric distance_metric_;

            // Node prefix name - if node names are not provided.
            std::string node_prefix_name_;

            // Flag to use the node value or not for computing the cost.
            bool use_node_value_;

            // Flag to create bidirectional edges between the nodes.
            bool bidirectional_;

            // List of node names in the environment.
            std::vector<std::string> node_names_;

            // List of node values in the environment.
            std::vector<RowVector> node_values_;

            // List of nodes in the environment.
            std::vector<Node<T, D>> nodes_;

            // Create node names in the environment.
            void createNodeNames(const std::vector<std::string>& node_names);

            // Initialize node values in the environment.
            void createNodeValues(const std::vector<RowVector>& node_values);

            // Initialize node items in the environment.
            void initializeNodeItems(
                const std::vector<RowVector>& node_values,
                const std::vector<std::string>& node_names);

            // Create nodes in the environment.
            void createNodes();

            // Create edges between the nodes in the environment.
            void createEdges();

        public:
            /**
             * @brief Public members of `Environment`
             */

            /**
             * @brief Constructor of the `Environment` class.
             * @param num_nodes - number of nodes in the environment.
             * @param edges - edges between the nodes in the environment.
             * @param distance_metric - distance metric used to compute the cost - default is `EUCLIDEAN`- refer `DistanceMetric` enum.
             * @param node_prefix_name - prefix name for the nodes in the environment. - default is `Node_`.
             * @param use_node_value - flag to use the node value or not for computing the cost - default is `true`.
             * @param bidirectional - flag to create bidirectional edges between the nodes - default is `true`.
            */
            Environment(
                const std::size_t& num_nodes,
                const std::vector<std::pair<std::size_t, std::size_t>>& edges,
                const DistanceMetric& distance_metric = DistanceMetric::EUCLIDEAN,
                const std::string& node_prefix_name = "Node_",
                const bool& use_node_value = true,
                const bool& bidirectional = true);

            /**
             * @brief Destructor of the `Environment` class.
             */
            ~Environment();

            /**
             * @brief Get the number of nodes in the environment.
             * @return Number of nodes in the environment.
             */
            const std::size_t getNumNodes() const;

            /**
             * @brief Get the list of nodes in the environment.
             * @return List of nodes in the environment.
             */
            const std::vector<Node<T, D>> getNodes() const;

            /**
             * @brief Get the node at index `index` in the environment.
             * @param index - Node at index `index` in the environment.
             */
            const Node<T, D>& getNode(const std::size_t& index) const;

            /**
             * @brief Get the edges between the nodes in the environment.
             * @return Edges between the nodes in the environment.
             */
            const std::vector<std::pair<std::size_t, std::size_t>> getEdges() const;
            
            /**
             * @brief Create the environment.
             * @param node_values - values of the nodes in the environment.
             * @param node_names - names of the nodes in the environment [optional].
             */
            void create(const std::vector<RowVector>& node_values = std::vector<RowVector>(),
                const std::vector<std::string>& node_names = std::vector<std::string>());

            /**
             * @brief Perform space search in the environment.
             * @param start_node - start node for the search.
             * @param goal_node - goal node for the search.
             * @param method - search algorithm to use - refer to `SearchAlgorithm` enum - default is A* search.
             * @return std::vector<Node<T, D>> - path from the start node to the goal node.
             */
            const std::vector<Node<T, D>> search(
                const Node<T, D>& start_node,
                const Node<T, D>& goal_node,
                const SearchAlgorithm& method = SearchAlgorithm::BREADTH_FIRST_SEARCH);
    };

} // namespace search

#endif // SEARCH_ENVIRONMENT_H
