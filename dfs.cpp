#include <vector>
#include "dfs.h"
#include "grid.h"

std::vector<std::pair<int, int>> Dfs::solve(Grid &grid){ 
  nodesVisited = 0;
  nodePool.clear();
  nodePool.reserve(grid.getWidth() * grid.getHeight());
  while (!open.empty()){
    open.pop();
  }
  visited.clear();
  
  nodePool.push_back(Node(grid.start.x, grid.start.y));
  open.push(0);
  visited = std::vector<std::vector<bool>>(grid.getHeight(), std::vector<bool>(grid.getWidth(), false));
  visited[grid.start.x][grid.start.y] = true;
  while (!open.empty()){
    int currentIndex = open.top();
    open.pop();
    nodesVisited++;
    if (nodePool[currentIndex].x == grid.end.x && nodePool[currentIndex].y == grid.end.y){
      std::vector<std::pair<int, int>> path;
      int index = currentIndex;
      while (index != -1){
        path.push_back(std::make_pair(nodePool[index].x, nodePool[index].y));
        index = nodePool[index].parentIndex;
      }
      while (!open.empty()){
        open.pop();
      }
      return path;
    }
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
    for (int i = 0; i < 8; i++){
     int nx = nodePool[currentIndex].x + dx[i];
     int ny = nodePool[currentIndex].y + dy[i];
     if (nx < 0 || ny < 0 || nx >= grid.getHeight() || ny >= grid.getWidth()){
       continue;
     }
     if (grid.getCell(nx,ny) == CellType::Wall || visited[nx][ny]){
       continue;
     }
     
     nodePool.push_back(Node(nx, ny));
     visited[nx][ny] = true;
     open.push(nodePool.size() - 1);
     nodePool[nodePool.size() -1].parentIndex = currentIndex;
    }
  }
  return {};
}

