#include "grid.h"
#include <iostream>

int main(int argc, char *argv[]){
  Grid grid;

  if (!(argc > 1)){
    std::cerr << "File path was not given, exiting";
    return 1;
  }
  grid.loadFromFile(argv[1]);
  grid.print();
  return 0;  
}
