#ifndef BFS_H
#define BFS_H

#include <queue>
#include <vector>
#include "grid.h"

struct Node {
  Node(int x, int y) : x(x), y(y) {}
  int x = 0;
  int y = 0;
  int parentIndex = -1;
};

class Bfs {
  public:
    Bfs(){};
    std::vector<Node> nodePool;
    std::queue<int> open;
    std::vector<std::vector<bool>> visited;
    std::vector<std::pair<int, int>> solve(Grid &grid);
};

#endif
