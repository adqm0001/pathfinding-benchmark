#include <iostream>
#include <chrono>
#include "grid.h"

struct BenchmarkResult {
  double time;
  int pathLength;
  int nodesVisited;
};
class Benchmark {
  public: 
    Benchmark(){};
    template <typename Algo>
    BenchmarkResult run(Algo &algo, Grid &grid) {
      auto start = std::chrono::high_resolution_clock::now();
      auto path = algo.solve(grid);
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::micro> duration = end - start;

      return {duration.count(), (int)path.size(), algo.nodesVisited};
    }
};
