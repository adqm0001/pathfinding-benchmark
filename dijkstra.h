#ifndef DIJKSTRA_H 
#define DIJKSTRA_H 

#include <queue>
#include <vector>
#include "node.h"
#include "grid.h"
#include "comparator.h"

class Dijkstra {
  public:
    Dijkstra() : open(CompareG(nodePool)) {} 
    std::vector<Node> nodePool;
    std::priority_queue<int, std::vector<int>, CompareG> open;
    std::vector<std::vector<bool>> visited;
    std::vector<std::vector<int>> bestG;
    std::vector<std::pair<int, int>> solve(Grid &grid);
    int nodesVisited;
};
#endif
