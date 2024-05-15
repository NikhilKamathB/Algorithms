#ifndef SEARCH_ENVIRONMENT_H
#define SEARCH_ENVIRONMENT_H

/**
 * @file environment.h
 * @brief Contains the definition of the `Environment` class.
 */

#include <utils.h>

namespace search
{
    /**
     * @class Environment
     * @brief This class represents the environment in which the search is performed.
     * @details An instance of the `Environment` class represents the environment in which the search is performed.
     * It contains a bunch of nodes and the connections between them.
     * Bottom line, the `Environment` class is a graph and contains all the information needed to perform a search.
    */
    template <typename T, unsigned int D>
    class Environment
    {
        private:
            /**
             * @brief Private members of `Environment`
             */
            ;

        public:
            /**
             * @brief Public members of `Environment`
             */

            Environment();
            ~Environment();
    };

} // namespace search

#endif // SEARCH_ENVIRONMENT_H
