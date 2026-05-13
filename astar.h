#ifndef ASTAR_H
#define ASTAR_H

#include <queue>
#include <vector>
#include "node.h"
#include "grid.h"

struct CompareNode {
  std::vector<Node> &pool;

  CompareNode(std::vector<Node> &pool) : pool(pool) {}

  bool operator()(int a, int b) const {
    return pool[a].f_cost > pool[b].f_cost;
  }
};

class Astar {
  public:
    Astar() : open(CompareNode(nodePool)) {} 
    std::vector<Node> nodePool;
    std::priority_queue<int, std::vector<int>, CompareNode> open;
    std::vector<std::vector<bool>> visited;
    std::vector<std::vector<int>> bestG;
    std::vector<std::pair<int, int>> solve(Grid &grid);
};
#endif
