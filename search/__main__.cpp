#include <iostream>
#include <search/environment.h>

using T = FLOATING_POINT_TYPE;  // Data type - [double, float]
constexpr unsigned int D = DIM; // Dimensions - [1, 2, 3]

int main(int argc, char *argv[])
{
    // Create an instance of the `Environment` class
    search::Environment<T, D> environment(
        /*num_nodes=*/5,
        /*edges=*/{{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}}
    );
    return 0;
}