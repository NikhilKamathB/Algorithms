#ifndef SEARCH_ENVIRONMENT_GRAPH_H
#define SEARCH_ENVIRONMENT_GRAPH_H

/**
 * @file graph.h
 * @brief A graph based environment for search algorithms.
 */

#include <plog/Log.h>
#include <search/cost/cost.h>
#include <search/environment/environment.h>
#include <search/search/dfs.h>

namespace search
{

    /**
     * @class Graph
     * @brief This class represents a graph based environment (nodes connected by edges) in which the search algorithm operates.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    class Graph : public Environment<T, D>
    {

        using SearchAlgorithm = utils::SearchAlgorithm;

    private:
        // Edges between nodes
        std::vector<std::pair<std::size_t, std::size_t>> edges_;

        // List of nodes
        std::vector<Node<T, D> *> nodes_;

        // Cost functions - pointer because we usually pass a child class of Cost<T, D> and we need polymorphism
        const Cost<T, D> *cost_function_;

        // Function to create connected graph
        void _create_connected_graph()
        {
            PLOGD << "Creating connected graph.";
            for (const std::pair<std::size_t, std::size_t> &edge : edges_)
            {
                nodes_[edge.first]->add_neighbor(nodes_[edge.second]);
            }
        }

    public:
        /**
         * @brief Construct a new Graph object.
         * @param nodes list of nodes in the graph (raw pointers).
         * @param edges list of edges in the graph.
         * @param cost_function cost function for the graph.
         */
        Graph(const std::vector<Node<T, D> *> &nodes,
              const std::vector<std::pair<std::size_t, std::size_t>> &edges,
              const Cost<T, D> &cost_function)
            : nodes_(nodes),
              edges_(edges),
              cost_function_(&cost_function)
        {
            PLOGD << "Initializing Graph object with " << nodes_.size() << " raw nodes pointers and " << edges_.size() << " edges.";
        }

        /**
         * @brief Construct a new Graph object.
         * @param nodes list of nodes in the graph (smart pointers).
         * @param edges list of edges in the graph.
         * @param cost_function cost function for the graph.
         */
        Graph(const std::vector<std::unique_ptr<Node<T, D>>> &nodes,
              const std::vector<std::pair<std::size_t, std::size_t>> &edges,
              const Cost<T, D> &cost_function)
            : edges_(edges),
              cost_function_(&cost_function)
        {
            PLOGD << "Initializing Graph object with " << nodes.size() << " smart nodes pointers and " << edges_.size() << " edges.";
            // Convert unique_ptr to raw pointers for internal use
            for (const std::unique_ptr<Node<T, D>> &node : nodes)
            {
                nodes_.emplace_back(node.get());
            }
        }

        /**
         * @brief Destructor for the Graph class.
         */
        ~Graph()
        {
            PLOGD << "Destroying Graph object.";
        }

        /**
         * @brief Initialize the graph.
         */
        void initialize() override
        {
            PLOGD << "Initializing Graph based environment.";
            this->_create_connected_graph();
        }

        /**
         * @brief Get the node at a given index.
         * @param index Index of the node to retrieve.
         * @return const Node<T, D>* Pointer to the node at the given index.
         */
        const Node<T, D> *get_node(const std::size_t index) const
        {
            PLOGD << "Retrieving node at index: " << index;
            return nodes_[index];
        }

        /**
         * @brief Get the cost of going from node A to node B (`from_node` to `to_node`) | A -> B.
         * @param from_node node A.
         * @param to_node node B.
         * @return const double cost of going `from_node` to `to_node`.
         */
        const double get_cost(const Node<T, D> &from_node,
                              const Node<T, D> &to_node) const override
        {
            PLOGD << "Getting cost from node: " << from_node.get_name() << " to node: " << to_node.get_name();
            return cost_function_->get_cost(from_node, to_node);
        }

        /**
         * @brief Perform space search and return paths from start to goal for a graph based environment.
         * @param start_node The starting node.
         * @param goal_node The goal node.
         * @param search_algorithm The search algorithm to use (DFS, BFS, UCS, A_STAR, etc) - default is DFS.
         * @return A vectors of pairs representing the paths from start to goal along with their step costs.
         */
        const std::vector<std::pair<const Node<T, D> *, double>> search(
            const Node<T, D> &start_node,
            const Node<T, D> &goal_node,
            SearchAlgorithm search_algorithm = SearchAlgorithm::DFS) const override
        {
            PLOGD << "Performing search from node: " << start_node.get_name() << " to node: " << goal_node.get_name();
            switch (search_algorithm)
            {
            case SearchAlgorithm::DFS:
                PLOGD << "Using DFS search algorithm.";
                return DFS<T, D, Graph<T, D>>().search(start_node, goal_node, *this);
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

        /**
         * @brief << operator - function for streaming the Graph to an output stream.
         * @param os output stream.
         * @param env environment to stream.
         * @return std::ostream& output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const Graph<T, D> &env)
        {
            os << "Graph[Nodes: " << env.nodes_.size() << " | Edges: " << env.edges_.size() << "]";
            return os;
        }
    };

} // namespace search

#endif // SEARCH_ENVIRONMENT_GRAPH_H