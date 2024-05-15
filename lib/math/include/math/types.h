#ifndef MATH_TYPES_H
#define MATH_TYPES_H

/**
 * @file math.h
 * @brief Contains the definition of the data structures that can be used in mathematical computations (header only file).
 */

#include <Eigen/Dense>

namespace math
{

    // Row vector type
    template <typename T, unsigned int D>
    using RowVector = Eigen::Matrix<T, 1, D>;

    // Column vector type
    template <typename T, unsigned int D>
    using ColumnVector = Eigen::Matrix<T, D, 1>;

    // Matrix type
    template <typename T, unsigned int R, unsigned int C>
    using Matrix = Eigen::Matrix<T, R, C>;

} // namespace math

#endif // MATH_TYPES_H