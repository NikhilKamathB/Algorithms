/**
 * @file environment.cpp
 * @brief Contains the implementation of the `Environment` class.
 */

#include <search/search/bfs.h>
#include <search/search/dfs.h>
#include <search/search/ucs.h>
#include <search/environment.h>

namespace search
{
    template <typename T, unsigned int D>
    Environment<T, D>::Environment(
        const std::size_t &num_nodes,
        const std::vector<std::pair<std::size_t, std::size_t>> &edges,
        const DistanceMetric &distance_metric,
        const std::string &node_prefix_name,
        const bool &use_node_value,
        const bool &bidirectional)
        : num_nodes_(num_nodes), edges_(edges),
          distance_metric_(distance_metric), node_prefix_name_(node_prefix_name),
          use_node_value_(use_node_value), bidirectional_(bidirectional)
    {
        nodes_.reserve(num_nodes_);
        node_names_.reserve(num_nodes_);
        node_values_.reserve(num_nodes_);
    }

    template <typename T, unsigned int D>
    Environment<T, D>::~Environment() {}

    template <typename T, unsigned int D>
    void Environment<T, D>::createNodeNames(const std::vector<std::string> &node_names)
    {
        if (!node_names.empty() && node_names.size() == num_nodes_)
        {
            node_names_ = node_names;
        }
        else
        {
            for (std::size_t i = 0; i < num_nodes_; ++i)
            {
                node_names_.emplace_back(node_prefix_name_ + std::to_string(i));
            }
        }
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::createNodeValues(const std::vector<RowVector> &node_values)
    {
        if (!node_values.empty() && node_values.size() == num_nodes_)
        {
            node_values_ = node_values;
        }
        else
        {
            for (std::size_t i = 0; i < num_nodes_; ++i)
            {
                node_values_.emplace_back(RowVector::Zero());
            }
        }
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::initializeNodeItems(
        const std::vector<RowVector> &node_values,
        const std::vector<std::string> &node_names)
    {
        this->createNodeNames(node_names);
        this->createNodeValues(node_values);
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::createNodes()
    {
        for (std::size_t i = 0; i < num_nodes_; ++i)
        {
            nodes_.emplace_back(
                Node<T, D>(node_names_[i], node_values_[i], distance_metric_, use_node_value_));
        }
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::createEdges()
    {
        for (const std::pair<std::size_t, std::size_t> &edge : edges_)
        {
            nodes_[edge.first].addNeighbor(nodes_[edge.second]);
            if (bidirectional_)
            {
                nodes_[edge.second].addNeighbor(nodes_[edge.first]);
            }
        }
    }

    template <typename T, unsigned int D>
    const std::size_t Environment<T, D>::getNumNodes() const
    {
        return num_nodes_;
    }

    template <typename T, unsigned int D>
    const std::vector<Node<T, D>> Environment<T, D>::getNodes() const
    {
        return nodes_;
    }

    template <typename T, unsigned int D>
    const Node<T, D> &Environment<T, D>::getNode(const std::size_t &index) const
    {
        return nodes_[index];
    }

    template <typename T, unsigned int D>
    const std::vector<std::pair<std::size_t, std::size_t>> Environment<T, D>::getEdges() const
    {
        return edges_;
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::create(const std::vector<RowVector> &node_values,
                                   const std::vector<std::string> &node_names)
    {
        this->initializeNodeItems(node_values, node_names);
        this->createNodes();
        this->createEdges();
    }

    template <typename T, unsigned int D>
    const std::vector<std::pair<Node<T, D>, T>> Environment<T, D>::search(
        const Node<T, D> &start_node,
        const Node<T, D> &goal_node,
        const SearchAlgorithm &search_algorithm)
    {
        switch (search_algorithm)
        {
        case SearchAlgorithm::BREADTH_FIRST_SEARCH:
        {
            BFS<T, D> bfs;
            return bfs.solve(start_node, goal_node);
        }
        case SearchAlgorithm::DEPTH_FIRST_SEARCH:
        {
            DFS<T, D> dfs;
            return dfs.solve(start_node, goal_node);
        }
        case SearchAlgorithm::UNIFORM_COST_SEARCH:
        {
            UCS<T, D> ucs;
            return ucs.solve(start_node, goal_node);
        }
        default:
        {
            DFS<T, D> bfs;
            return bfs.solve(start_node, goal_node);
        }
        }
    }

    // Explicit template instantiation
    template class Environment<float, 1U>;
    template class Environment<float, 2U>;
    template class Environment<float, 3U>;
    template class Environment<double, 1U>;
    template class Environment<double, 2U>;
    template class Environment<double, 3U>;

} // namespace search