#ifndef SEARCH_UTILS_H
#define SEARCH_UTILS_H

/**
 * @file utils.h
 * @brief Contains utility functions/definitions used in the search library.
 */

#include <Eigen/Dense>

namespace search
{
    /**
     * @brief Types of distance metrics.
     * @details The `distance` member of the `Cost` class can be
     * computed using one of the following distance metrics:
     * 1. Eucledean    2. Manhattan
     */
    enum class DistanceMetric
    {
        EUCLIDEAN,
        MANHATTAN
    };

    /**
     * @brief Types of search algorithms.
     * @details The `search_algorithm` member of the `Search` class can be
     * one of the following search algorithms:
     * 1. Breadth First Search    2. Depth First Search
     * 3. Uniform Cost Search     4. A*
     */
    enum class SearchAlgorithm
    {
        BREADTH_FIRST_SEARCH,
        DEPTH_FIRST_SEARCH,
        UNIFORM_COST_SEARCH,
        A_STAR
    };
} // namespace search

#endif // SEARCH_UTILS_H