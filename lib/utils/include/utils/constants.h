#ifndef UTILS_CONSTANTS_H
#define UTILS_CONSTANTS_H

/**
 * @file constants.h
 * @brief Contains the declaration of the constants used in the library (header only file).
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

    // Floating point precision
    static constexpr double floating_point_precision{1e-6};

} // namespace utils

#endif // UTILS_CONSTANTS_H