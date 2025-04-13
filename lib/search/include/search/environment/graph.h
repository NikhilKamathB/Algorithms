#ifndef SEARCH_ENVIRONMENT_GRAPH_H
#define SEARCH_ENVIRONMENT_GRAPH_H

/**
 * @file graph.h
 * @brief Contains the declaration of the `Graph` class.
 */

#include <search/environment/environment.h>

namespace search
{

    /**
     * @class Graph
     * @brief This class represents a graph based environment (nodes connected by edges) in which the search algorithm operates.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class Graph : protected Environment<T, D>
    {

        using SearchAlgorithm = utils::SearchAlgorithm;

    private:
        // Edges between nodes
        std::vector<std::pair<std::size_t, std::size_t>> edges_;

        // List of nodes
        std::vector<Node<T, D> *> nodes_;

        // List of cost functions
        std::vector<const Cost<T, D> *> cost_functions_;

        // Function to create connected graph
        void _createConnectedGraph();

    public:

        /**
         * @brief Construct a new Graph object.
         * @param nodes list of nodes in the graph.
         * @param edges list of edges in the graph.
         * @param cost_functions list of cost functions for the graph.
         */
        Graph(const std::vector<Node<T, D> *> &nodes,
              const std::vector<std::pair<std::size_t, std::size_t>> &edges,
              const std::vector<const Cost<T, D> *> &cost_functions);
         
        /**
         * @brief Destructor for the Graph class.
         */
        ~Graph();

        /**
         * @brief Initialize the graph.
         */
        void initialize() override;

        /** 
         * @brief Perform space search and return paths from start to goal for a graph based environment.
         * @param start_node The starting node.
         * @param goal_node The goal node.
         * @param search_algorithm The search algorithm to use (DFS, BFS, UCS, A_STAR) - default is DFS.
         * @return A vector of vectors of pairs representing the paths from start to goal along with their step costs.
         */
        const std::vector<std::vector<std::pair<const Node<T, D> *, double>>> search(
            const Node<T, D> &start_node,
            const Node<T, D> &goal_node,
            SearchAlgorithm search_algorithm = SearchAlgorithm::DFS) const override;

        /**
         * @brief << operator - function for streaming the Graph to an output stream.
         * @param os output stream.
         * @param env environment to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const Graph<T, D> &env);
    };

} // namespace search

#endif // SEARCH_ENVIRONMENT_GRAPH_H