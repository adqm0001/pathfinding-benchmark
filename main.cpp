#include "grid.h"
#include "astar.h"
#include <iostream>
#include <iomanip>
#include "benchmark.h"
#include "astar.h"
#include "dijkstra.h"
#include "bfs.h"
#include "dfs.h"


void printTable(BenchmarkResult astar, BenchmarkResult dijkstra, BenchmarkResult bfs, BenchmarkResult dfs) {
  std::cout << std::left << std::setw(12) << "Algorithm"
            << std::setw(12) << "Time (us)"
            << std::setw(12) << "Path Length"
            << std::setw(12) << "Nodes Visited" << "\n";
  std::cout << std::string(48, '-') << "\n";
  std::cout << std::left << std::setw(12) << "A*"
            << std::setw(12) << astar.time
            << std::setw(12) << astar.pathLength
            << std::setw(12) << astar.nodesVisited << "\n";
  std::cout << std::left << std::setw(12) << "Dijkstra"
            << std::setw(12) << dijkstra.time
            << std::setw(12) << dijkstra.pathLength
            << std::setw(12) << dijkstra.nodesVisited << "\n";
  std::cout << std::left << std::setw(12) << "Bfs"
            << std::setw(12) << bfs.time
            << std::setw(12) << bfs.pathLength
            << std::setw(12) << bfs.nodesVisited << "\n";
  std::cout << std::left << std::setw(12) << "Dfs"
            << std::setw(12) << dfs.time
            << std::setw(12) << dfs.pathLength
            << std::setw(12) << dfs.nodesVisited << "\n";
}

int main(int argc, char *argv[]){
  Grid grid;
  Astar astar;
  Dijkstra dijkstra;
  Bfs bfs;
  Dfs dfs;

  if (!(argc > 1)){
    std::cerr << "File path was not given, exiting.";
    return 1;
  }
  grid.loadFromFile(argv[1]);
  grid.print();

  Benchmark bench;
  BenchmarkResult astarResult = bench.run(astar, grid);
  BenchmarkResult dijkstraResult = bench.run(dijkstra, grid);
  BenchmarkResult bfsResult = bench.run(bfs, grid);
  BenchmarkResult dfsResult = bench.run(dfs, grid);

  printTable(astarResult, dijkstraResult, bfsResult, dfsResult);

  return 0;  
}
