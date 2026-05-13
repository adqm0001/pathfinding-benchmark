#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>

enum class CellType { Empty, Wall, Start, End };

struct Point {
  int x, y;
};

class Grid {
public:
    Grid();
    void loadFromFile(const std::string& path);
    void print() const;

    int getWidth() const;
    int getHeight() const;
    CellType getCell(int x, int y) const;
    Point start;
    Point end;

private:
    int width, height;
    std::vector<std::vector<CellType>> cells;
};

#endif
