#include "grid.h"
#include "astar.h"
#include <iostream>

int main(int argc, char *argv[]){
  Grid grid;
  Astar astar;

  if (!(argc > 1)){
    std::cerr << "File path was not given, exiting";
    return 1;
  }
  grid.loadFromFile(argv[1]);
  grid.print();
  std::vector<std::pair<int, int>> path = astar.solve(grid);
  for (size_t i = 0; i < path.size(); i++) {
    std::cout << "(" << path[i].first << ", " << path[i].second << ")\n";
  }
  return 0;  
}
