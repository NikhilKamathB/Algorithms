#ifndef MATH_TYPES_H
#define MATH_TYPES_H

/**
 * @file math.h
 * @brief Contains the declaration of the data structures that can be used in mathematical computations (header only file).
 */

#include <Eigen/Dense>

namespace math
{

    /**
     * @brief Row vector type
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    using RowVector = Eigen::Matrix<T, 1, D>;

    /**
     * @brief Column vector type
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    using ColumnVector = Eigen::Matrix<T, D, 1>;

    /**
     * @brief Matrix type
     * @tparam T Type.
     * @tparam R Rows.
     * @tparam C Columns.
     */
    template <typename T, unsigned int R, unsigned int C>
    using Matrix = Eigen::Matrix<T, R, C>;

} // namespace math

#endif // MATH_TYPES_H