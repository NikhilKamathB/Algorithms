#ifndef UTILS_CONSTANTS_H
#define UTILS_CONSTANTS_H

/**
 * @file constants.h
 * @brief Contains constants which will be used project wide.
 */

#include <cstdint>

namespace utils
{
    // Distance metric constants
    enum class DistanceMetric : uint8_t
    {
        EUCLIDEAN,
        MANHATTAN
    };

    // Search Algorithms
    enum class SearchAlgorithm : uint8_t
    {
        DFS,
        BFS,
        UCS,
        A_STAR
    };

    // Floating point precision
    static constexpr double floating_point_precision{1e-6};

} // namespace utils

#endif // UTILS_CONSTANTS_H