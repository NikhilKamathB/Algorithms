/**
 * @file graph.cpp
 * @brief Contains the implementation of the `Graph` class.
 */

#include <search/environment/graph.h>

namespace search
{

    template <typename T, unsigned int D>
    Graph<T, D>::Graph(const std::vector<Node<T, D> *> &nodes,
                       const std::vector<std::pair<std::size_t, std::size_t>> &edges,
                       const std::vector<const Cost<T, D> *> &cost_functions)
        : nodes_(nodes),
          edges_(edges),
          cost_functions_(cost_functions)
    {
        PLOGD << "Initializing Graph object with " << nodes_.size() << " nodes and " << edges_.size() << " edges.";
    }

    template <typename T, unsigned int D>
    Graph<T, D>::~Graph()
    {
        PLOGD << "Destroying Graph object.";
    }

    template <typename T, unsigned int D>
    void Graph<T, D>::_createConnectedGraph()
    {
        PLOGD << "Creating connected graph.";
        for (const std::pair<std::size_t, std::size_t> &edge : edges_)
        {
            nodes_[edge.first]->addNeighbor(nodes_[edge.second]);
        }
    }

    template <typename T, unsigned int D>
    void Graph<T, D>::initialize()
    {
        PLOGD << "Initializing Graph based environment.";
        this->_createConnectedGraph();
    }

    template <typename T, unsigned int D>
    const std::vector<std::vector<std::pair<const Node<T, D> *, double>>> Graph<T, D>::search(
        const Node<T, D> &start_node,
        const Node<T, D> &goal_node,
        SearchAlgorithm search_algorithm) const
    {
        PLOGD << "Performing search from node: " << start_node.getName() << " to node: " << goal_node.getName();
        switch (search_algorithm)
        {
        case SearchAlgorithm::DFS:
            PLOGD << "Using DFS search algorithm.";
            break;
        case SearchAlgorithm::BFS:
            PLOGD << "Using BFS search algorithm.";
            break;
        case SearchAlgorithm::UCS:
            PLOGD << "Using UCS search algorithm.";
            break;
        case SearchAlgorithm::A_STAR:
            PLOGD << "Using A* search algorithm.";
            break;
        default:
            PLOGE << "Unknown search algorithm.";
            throw std::invalid_argument("Unknown search algorithm.");
        }
        return {};
    }

        template <typename T, unsigned int D>
        std::ostream &operator<<(std::ostream &os, const Graph<T, D> &env)
    {
        os << "Graph[Nodes: " << env.nodes_.size() << " | Edges: " << env.edges_.size() << "]";
        return os;
    }


} // namespace search