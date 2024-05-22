#include <iostream>
#include <search/environment.h>

using T = FLOATING_POINT_TYPE;  // Data type - [double, float]
constexpr unsigned int D = DIM; // Dimensions - [1, 2, 3]

using Node = search::Node<T, D>;
using Environment = search::Environment<T, D>;

void printPath(const std::vector<Node>& path)
{
    for (std::size_t i = 0; i < path.size(); ++i)
    {
        std::cout << path[i].getName();
        if (i < path.size() - 1)
        {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{   
    // Create an object of the `Environment` class
    Environment env = Environment(
        /*num_nodes=*/6,
        /*edges=*/{{0, 1}, {0, 2}, {0, 3}, {2, 4}, {3, 5}}
    );
    // Create the environment
    env.create();
    // Perform state space search - BFS
    std::vector<Node> bfs_path = env.search(env.getNode(0), env.getNode(5));
    // Print the path
    std::cout << "BFS Path: ";
    printPath(bfs_path);
    // Perform state space search - DFS
    std::vector<Node> dfs_path = env.search(env.getNode(0), env.getNode(5), search::SearchAlgorithm::DEPTH_FIRST_SEARCH);
    // Print the path
    std::cout << "DFS Path: ";
    printPath(dfs_path);
    return 0;
}