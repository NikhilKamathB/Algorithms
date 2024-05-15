/**
 * @file hasher.cpp
 * @brief Contains the implementation of hashers for math objects.
 */

#include <math/hasher.h>

namespace math
{

    template <typename T, unsigned int R, unsigned int C>
    std::size_t MatrixHasher<T, R, C>::operator()(const Matrix<T, R, C> &matrix, std::size_t seed) const noexcept
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

} // namespace math
