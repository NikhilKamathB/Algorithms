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

    private:
        // Number of nodes in the graph
        std::size_t num_nodes_;

        // Edges between nodes
        std::vector<std::pair<std::size_t, std::size_t>> edges_;

        // Enable bidirectional edges
        bool bidirectional_;

        // List of nodes in the graph
        std::vector<std::shared_ptr<Node<T, D>>> nodes_;

    public:
        /**
         * @brief Destructor for the Graph class.
         */
        ~Graph() = default;
     
    };

} // namespace search

#endif // SEARCH_ENVIRONMENT_GRAPH_H