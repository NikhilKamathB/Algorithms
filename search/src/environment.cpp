/**
 * @file environment.cpp
 * @brief Contains the implementation of the `Environment` class.
 */

#include <search/environment.h>

namespace search
{
    template <typename T, unsigned int D>
    Environment<T, D>::Environment(
        const std::size_t& num_nodes,
        const std::vector<std::pair<std::size_t, std::size_t>>& edges,
        const DistanceMetric& distance_metric,
        const std::string& node_prefix_name,
        const bool& use_node_value,
        const bool& bidirectional)
        : num_nodes_(num_nodes), edges_(edges), 
        distance_metric_(distance_metric), node_prefix_name_(node_prefix_name), 
        use_node_value_(use_node_value), bidirectional_(bidirectional) {}

    template <typename T, unsigned int D>
    Environment<T, D>::~Environment() {}

    template <typename T, unsigned int D>
    void Environment<T, D>::createNodeNames(const std::vector<std::string>& node_names)
    {
        if (!node_names.empty() && node_names.size() == num_nodes_)
        {
            node_names_ = node_names;
        }
        else {
            for (std::size_t i = 0; i < num_nodes_; ++i) {
                node_names_.push_back(node_prefix_name_ + std::to_string(i));
            }
        }
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::createNodeValues(const std::vector<RowVector>& node_values)
    {
        if (!node_values.empty() && node_values.size() == num_nodes_)
        {
            node_values_ = node_values;
        }
        else {
            for (std::size_t i = 0; i < num_nodes_; ++i) {
                node_values_.push_back(RowVector::Zero());
            }
        }
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::initializeNodeItems(
        const std::vector<RowVector>& node_values,
        const std::vector<std::string>& node_names)
    {
        this->createNodeNames(node_names);
        this->createNodeValues(node_values);
    }


    template <typename T, unsigned int D>
    void Environment<T, D>::createNodes()
    {
        for (std::size_t i = 0; i < num_nodes_; ++i) {
            nodes_.push_back(
                Node<T, D>(node_names_[i], node_values_[i], distance_metric_, use_node_value_)
            );
        }
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::createEdges()
    {
        for (const std::pair<std::size_t, std::size_t>& edge : edges_) {
            Node<T, D> node_1 = nodes_[edge.first];
            Node<T, D> node_2 = nodes_[edge.second];
            node_1.addNeighbor(node_2);
            if (bidirectional_) {
                node_2.addNeighbor(node_1);
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
    const std::vector<std::pair<std::size_t, std::size_t>> Environment<T, D>::getEdges() const
    {
        return edges_;
    }

    template <typename T, unsigned int D>
    void Environment<T, D>::create(const std::vector<RowVector>& node_values,
        const std::vector<std::string>& node_names)
    {
        this->createNodes();
        this->createEdges();
    }

    template <typename T, unsigned int D>
    const std::vector<Node<T, D>> Environment<T, D>::search(
        const Node<T, D>& start_node,
        const Node<T, D>& goal_node,
        const SearchAlgorithm& search_algorithm) {
        return nodes_;
    }

    // Explicit template instantiation
    template class Environment<float, 1U>;
    template class Environment<float, 2U>;
    template class Environment<float, 3U>;
    template class Environment<double, 1U>;
    template class Environment<double, 2U>;
    template class Environment<double, 3U>;

} // namespace search