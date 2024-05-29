/**
 * @file main.cpp
 * @brief Contains the main function to run the algorithms library | wrapper for python.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
#include <algorithms.h>

template <typename T, unsigned int D>
void registerNode(pybind11::module &m, const std::string &name)
{
    pybind11::class_<search::Node<T, D>>(m, name.c_str())
        .def("getName", &search::Node<T, D>::getName)
        .def("getValue", &search::Node<T, D>::getValue);
}

template <typename T, unsigned int D>
void registerAlgorithm(pybind11::module &m, const std::string &name)
{
    pybind11::class_<algorithms::Algorithm<T, D>>(m, name.c_str())
        .def(pybind11::init<>())
        .def("search", &algorithms::Algorithm<T, D>::search,
             pybind11::arg("num_nodes"),
             pybind11::arg("node_values"),
             pybind11::arg("node_names"),
             pybind11::arg("edges"),
             pybind11::arg("start_node_idx"),
             pybind11::arg("goal_node_idx"),
             pybind11::arg("method") = search::SearchAlgorithm::BREADTH_FIRST_SEARCH,
             pybind11::arg("distance_metric") = search::DistanceMetric::EUCLIDEAN,
             pybind11::arg("node_prefix_name") = "Node_",
             pybind11::arg("use_node_value") = true,
             pybind11::arg("bidirectional") = true);
}

PYBIND11_MODULE(algorithms, m)
{
    pybind11::enum_<search::SearchAlgorithm>(m, "SearchAlgorithm")
        .value("BREADTH_FIRST_SEARCH", search::SearchAlgorithm::BREADTH_FIRST_SEARCH)
        .value("DEPTH_FIRST_SEARCH", search::SearchAlgorithm::DEPTH_FIRST_SEARCH)
        .value("UNIFORM_COST_SEARCH", search::SearchAlgorithm::UNIFORM_COST_SEARCH)
        .value("A_STAR", search::SearchAlgorithm::A_STAR)
        .export_values();

    pybind11::enum_<search::DistanceMetric>(m, "DistanceMetric")
        .value("EUCLIDEAN", search::DistanceMetric::EUCLIDEAN)
        .value("MANHATTAN", search::DistanceMetric::MANHATTAN)
        .export_values();

    // Register the `Node` class.
    registerNode<float, 1>(m, "NodeF1");
    registerNode<float, 2>(m, "NodeF2");
    registerNode<float, 3>(m, "NodeF3");
    registerNode<double, 1>(m, "NodeD1");
    registerNode<double, 2>(m, "NodeD2");
    registerNode<double, 3>(m, "NodeD3");

    // Register the `Algorithm` class.
    registerAlgorithm<float, 1>(m, "AlgorithmF1");
    registerAlgorithm<float, 2>(m, "AlgorithmF2");
    registerAlgorithm<float, 3>(m, "AlgorithmF3");
    registerAlgorithm<double, 1>(m, "AlgorithmD1");
    registerAlgorithm<double, 2>(m, "AlgorithmD2");
    registerAlgorithm<double, 3>(m, "AlgorithmD3");
}