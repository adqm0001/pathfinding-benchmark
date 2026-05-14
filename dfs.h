#ifndef DFS_H
#define DFS_H

#include <stack>
#include <vector>
#include "grid.h"
#include "node.h"

class Dfs {
  public:
    Dfs(){};
    std::vector<Node> nodePool;
    std::stack<int> open;
    std::vector<std::vector<bool>> visited;
    std::vector<std::pair<int, int>> solve(Grid &grid);
    int nodesVisited;
};

#endif

