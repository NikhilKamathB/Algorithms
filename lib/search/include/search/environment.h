#ifndef SEARCH_ENVIRONMENT_H
#define SEARCH_ENVIRONMENT_H

/**
 * @file environment.h
 * @brief Contains the definition of the `Environment` class.
 * @details An instance of the `Environment` class represents the environment in which the search is performed.
 * You can create an environment with a bunch of nodes and the connections between them.
 * You can then trigger a search in the discretized space to find a path.
 */

#include <search/node.h>

namespace search
{
    /**
     * @class `Environment`
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

        // Number of nodes in the environment.
        std::size_t num_nodes_;

        // Edges between the nodes in the environment.
        std::vector<std::pair<std::size_t, std::size_t>> edges_;

        // Distance metric used to compute the cost.
        DistanceMetric distance_metric_;

        // List of distance metrics used to compute the cost for non-uniform cost computation.
        std::vector<DistanceMetric> distance_metrics_;

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

        /*
        * @brief Private members of `Environment`
        * Creates node names in the environment.
        * @param node_names names of the nodes in the environment.    
        */
        void createNodeNames(const std::vector<std::string> &node_names);

        /*
        * @brief Private members of `Environment`
        * Creates node values in the environment.
        * @param node_values values of the nodes in the environment.
        */
        void createNodeValues(const std::vector<RowVector> &node_values);

        /*
        * @brief Private members of `Environment`
        * Initializes the node items in the environment.
        * @param node_values values of the nodes in the environment.
        * @param node_names names of the nodes in the environment.
        */
        void initializeNodeItems(
            const std::vector<RowVector> &node_values,
            const std::vector<std::string> &node_names);

        /*
         * @brief Private members of `Environment`
         * Creates nodes in the environment by defaulting to non-uniform cost computation.
         * @param use_metrics flag to use the `distance_metrics` list for non-uniform cost computation.
         */
        void createNodes(const bool &use_metrics = true);

        /*
        * @brief Private members of `Environment`
        * Creates edges between the nodes in the environment.
        */
        void createEdges();

    public:

        /**
         * @brief Constructor of the `Environment` class.
         * The constructor initializes the environment with the given number of nodes and edges between them.
         * All nodes have a uniform cost computation method based on the distance metric provided.
         * @param num_nodes number of nodes in the environment.
         * @param edges edges between the nodes in the environment.
         * @param distance_metric distance metric used to compute the cost - default is `EUCLIDEAN`- refer `DistanceMetric` enum.
         * @param node_prefix_name prefix name for the nodes in the environment. - default is `Node_`.
         * @param use_node_value flag to use the node value or not for computing the cost - default is `true`.
         * @param bidirectional flag to create bidirectional edges between the nodes - default is `true`.
         */
        Environment(
            const std::size_t &num_nodes,
            const std::vector<std::pair<std::size_t, std::size_t>> &edges,
            const DistanceMetric &distance_metric = DistanceMetric::EUCLIDEAN,
            const std::string &node_prefix_name = "Node_",
            const bool &use_node_value = true,
            const bool &bidirectional = true);

        /**
         * @brief Constructor of the `Environment` class.
         * The constructor initializes the environment with the given number of nodes and edges between them.
         * All nodes may have a differnt cost computation method based on the list of distance metrics provided.
         * @param num_nodes number of nodes in the environment.
         * @param edges edges between the nodes in the environment.
         * @param distance_metrics distance metric used to compute the cost - it a list of metrics that enables variable cost compute in the search space.
         * @param node_prefix_name prefix name for the nodes in the environment. - default is `Node_`.
         * @param use_node_value flag to use the node value or not for computing the cost - default is `true`.
         * @param bidirectional flag to create bidirectional edges between the nodes - default is `true`.
         */
        Environment(
            const std::size_t &num_nodes,
            const std::vector<std::pair<std::size_t, std::size_t>> &edges,
            const std::vector<DistanceMetric> &distance_metrics,
            const std::string &node_prefix_name = "Node_",
            const bool &use_node_value = true,
            const bool &bidirectional = true);

        /**
         * @brief Destructor of the `Environment` class.
         */
        ~Environment();

        /**
         * @brief Get the node at index `index` in the environment.
         * @param index node at index `index` in the environment.
         * @return node at index `index` in the environment.
         */
        const Node<T, D> &getNode(const std::size_t &index) const;

        /**
         * @brief Create the environment for both uniform and non-uniform cost computation support.
         * This overloaded method defaults to non-uniform cost computation defined by the list of distance metrics - `distance_metrics`.
         * @param node_values values of the nodes in the environment.
         * If not provided, the values are set to zero vector.
         * @param node_names names of the nodes in the environment.
         * If not provided, the names are set to `Node_0`, `Node_1`, ...
         * @param use_metrics flag to use the `distance_metrics` list for non-uniform cost computation - default is `true`.
         */
        void create(const std::vector<RowVector> &node_values = std::vector<RowVector>(),
                    const std::vector<std::string> &node_names = std::vector<std::string>(),
                    const bool &use_metrics = false);

        /**
         * @brief Perform space search in the environment.
         * @param start_node start node for the search.
         * @param goal_node goal node for the search.
         * @param method search algorithm to use - refer to `SearchAlgorithm` enum - default is A* search.
         * @return std::vector<std::pair<Node<T, D>, T>> - path from the start node to the goal node with their cumulative costs.
         */
        const std::vector<std::pair<Node<T, D>, T>> search(
            const Node<T, D> &start_node,
            const Node<T, D> &goal_node,
            const SearchAlgorithm &method = SearchAlgorithm::BREADTH_FIRST_SEARCH);
    };

} // namespace search

#endif // SEARCH_ENVIRONMENT_H
