#include <iostream>
#include <search/environment.h>

using T = FLOATING_POINT_TYPE;  // Data type - [double, float]
constexpr unsigned int D = DIM; // Dimensions - [1, 2, 3]

using Node = search::Node<T, D>;
using Environment = search::Environment<T, D>;

int main(int argc, char *argv[])
{   
    // Create an object of the `Environment` class
    Environment env = Environment(
        /*num_nodes=*/6,
        /*edges=*/{{0, 1}, {0, 2}, {0, 3}, {2, 4}, {3, 5}}
    );
    // Create the environment
    env.create();
    // Perform state space search - DFS
    std::vector<Node> dfs_path = env.search(env.getNode(0), env.getNode(5));
    return 0;
}