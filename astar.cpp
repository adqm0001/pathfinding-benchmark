#include <queue>
#include <vector>
#include <cmath>
#include "node.h"
#include "grid.h"
#include "astar.h"

std::vector<std::pair<int, int>> Astar::solve(Grid &grid){
  nodePool.clear();
  nodePool.reserve(grid.getHeight() * grid.getWidth());
  while (!open.empty()) {
    open.pop();
  }
  visited.clear();
  bestG.clear();

  nodePool.push_back(Node(grid.start.x, grid.start.y));
  open.push(0); 
  visited = std::vector<std::vector<bool>>(grid.getHeight(), std::vector<bool>(grid.getWidth(), false));
  bestG = std::vector<std::vector<int>>(grid.getHeight(), std::vector<int>(grid.getWidth(), INT_MAX));
  while (open.size() > 0){
    int currentIndex = open.top();
    open.pop();
    visited[nodePool[currentIndex].x][nodePool[currentIndex].y] = true;
    if (nodePool[currentIndex].x == grid.end.x && nodePool[currentIndex].y == grid.end.y) {
      std::vector<std::pair<int, int>> path;
      int index = currentIndex;
      while (index != -1) {
        path.push_back(std::make_pair(nodePool[index].x, nodePool[index].y));
        index = nodePool[index].parentIndex;
      }
      while (!open.empty()) {
        open.pop();
      }
      return path;
    }
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++){
      int nx = nodePool[currentIndex].x + dx[i];
      int ny = nodePool[currentIndex].y + dy[i];

      if (nx < 0 || ny < 0 || nx >= grid.getHeight() || ny >= grid.getWidth()) {
        continue;
      }
      
      if (grid.getCell(nx, ny) == CellType::Wall || visited[nx][ny]){
        continue; 
      }

      int gCost = 0;
      if (dx[i] == 0 || dy[i] == 0){
        gCost = nodePool[currentIndex].g_cost + 10;
      } else {
        gCost = nodePool[currentIndex].g_cost + 14;
      }

      if (gCost >= bestG[nx][ny]){
        continue;
      }

      nodePool.push_back(Node(nx, ny));
      int neighborIndex = nodePool.size() - 1;

      nodePool[neighborIndex].g_cost = gCost;

      bestG[nx][ny] = nodePool[neighborIndex].g_cost;
      nodePool[neighborIndex].h_cost = sqrt(pow(nx - grid.end.x, 2) + pow(ny - grid.end.y, 2)) * 10;
      nodePool[neighborIndex].f_cost = nodePool[neighborIndex].g_cost + nodePool[neighborIndex].h_cost;
      
      nodePool[neighborIndex].parentIndex = currentIndex;

      open.push(neighborIndex);
    }
  };  
  while (!open.empty()){
    open.pop();
  }
  return {};
}

