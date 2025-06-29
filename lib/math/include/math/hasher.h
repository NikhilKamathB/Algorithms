#ifndef MATH_HASHER_H
#define MATH_HASHER_H

/**
 * @file hasher.h
 * @brief Math objects hasher warehouse.
 */

#include <boost/container_hash/hash.hpp>
#include <math/types.h>
#include <utils/constants.h>

namespace math
{

    /**
     * @struct MatrixHasher
     * @brief This struct represents a hasher for the `Matrix` type.
     * @tparam T Type.
     * @tparam R Rows.
     * @tparam C Columns.
     */
    template <typename T, unsigned int R, unsigned int C>
    struct MatrixHasher
    {
        /**
         * @brief Hash the matrix type and return the hash value of the matrix.
         * @param matrix matrix to hash.
         * @param seed seed value for the hash - seed will be alterd by the boost library - default is 42.
         * @return std::size_t - hash value of the matrix.
         */
        std::size_t operator()(const Matrix<T, R, C> &matrix, std::size_t seed = 42) const
        {
            if constexpr (std::is_floating_point_v<T>)
            {
                for (unsigned int r = 0; r < R; ++r)
                {
                    for (unsigned int c = 0; c < C; ++c)
                    {
                        boost::hash_combine(seed, static_cast<long long int>(matrix(r, c) / utils::floating_point_precision));
                    }
                }
            }
            else
            {
                for (unsigned int r = 0; r < R; ++r)
                {
                    for (unsigned int c = 0; c < C; ++c)
                    {
                        boost::hash_combine(seed, matrix(r, c));
                    }
                }
            }
            return seed;
        }
    };

    /**
     * @struct RowVectorHasher
     * @brief This struct represents a hasher for the `RowVector` type.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    using RowVectorHasher = MatrixHasher<T, 1U, D>;

    /**
     * @struct ColumnVectorHasher
     * @brief This struct represents a hasher for the `ColumnVector` type.
     * @tparam T Type.
     * @tparam D Dimension.
     */
    template <typename T, unsigned int D>
    using ColumnVectorHasher = MatrixHasher<T, D, 1U>;

} // namespace math

#endif // MATH_HASHER_H