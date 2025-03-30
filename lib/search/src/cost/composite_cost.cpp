/**
 * @file composite_cost.cpp
 * @brief Contains the implementation of the `CompositeCost` class.
 */

#include <search/cost/composite_cost.h>

namespace search
{
    template <typename T, unsigned int D>
    template <typename... C>
        requires(std::derived_from<C, Cost<T, D>> && ...)
    CompositeCost<T, D>::CompositeCost(const C &...cost_functions)
        : cost_functions_{cost_functions...}
    {
        PLOGD << "Initializing CompositeCost with " << sizeof...(cost_functions) << " cost functions and equal weights";
        weights_.resize(cost_functions.size(), 1.0);
    }

    template <typename T, unsigned int D>
    template <typename... C>
        requires(std::derived_from<C, Cost<T, D>> && ...)
    CompositeCost<T, D>::CompositeCost(const std::vector<double> &weights, const C &...cost_functions)
        : weights_(weights),
          cost_functions_{cost_functions...}
    {
        PLOGD << "Initializing CompositeCost with " << sizeof...(cost_functions) << " cost functions and " << weights.size() << " weights";
        if (weights_.size() != cost_functions_.size())
        {
            PLOGE << "Weights size does not match the number of cost functions passed";
            throw std::invalid_argument("Weights size must match the number of cost functions passed");
        }
    }

    template <typename T, unsigned int D>
    CompositeCost<T, D>::~CompositeCost()
    {
        PLOGD << "Destroying CompositeCost object";
    }

} // namespace search
