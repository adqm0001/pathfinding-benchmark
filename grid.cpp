#include <vector>
#include <iostream>
#include "grid.h"
#include <string>
#include <fstream>

Grid::Grid() {
  width = 0;
  height = 0;
}
void Grid::loadFromFile(const std::string &path) {
  std::ifstream file(path);
  if (!file.good()){
    std::cerr << "File was not found.";
    return;
  }
  std::string line;
  int rows = 0;
  while (std::getline(file, line)) {
    std::vector<CellType> row;
    int cols = 0;
    for (size_t i = 0; i < line.length(); i++){
      char currentChar = line[i];
      if (currentChar == ' '){
        continue;
      }
      CellType currentCell;
      switch (currentChar){
        case '.':
          currentCell = CellType::Empty;
          break;
        case '|':
          currentCell = CellType::Wall;
          break;
        case 'S':
          currentCell = CellType::Start;
          start.x = rows;
          start.y = cols;
          break;
        case 'E':
          currentCell = CellType::End;
          end.x = rows;
          end.y = cols; 
          break;
        default:
          std::cerr << "Unknown character defaulting to empty";
          currentCell = CellType::Empty;
          break;
        }
      row.push_back(currentCell);
      cols++;
    }
    cells.push_back(row);
    rows++;
  }
  height = cells.size();
  width = cells[0].size();
  file.close();
}

void Grid::print() const {
  for (size_t i = 0; i < cells.size(); i++){
    for (size_t j = 0; j < cells[i].size(); j++){
      CellType currentCell = cells[i][j];
      switch (currentCell){
        case CellType::Empty:
          std::cout << '.';
          break;
        case CellType::Wall:
          std::cout << '|';
          break;
        case CellType::Start:
          std::cout << 'S';
          break;
        case CellType::End:
          std::cout << 'E';
          break;
      }
    }
  std::cout << '\n';
  }
}
int Grid::getWidth() const {
  return width;
}
int Grid::getHeight() const {
  return height;
}
CellType Grid::getCell(int x, int y) const { 
  return cells[x][y];
}
