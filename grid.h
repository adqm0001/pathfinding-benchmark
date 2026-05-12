#include <vector>
#include <string>

#ifndef GRID_H
#define GRID_H

enum class CellType { Empty, Wall, Start, End };

class Grid {
public:
    Grid();
    void loadFromFile(const std::string& path);
    void print() const;

    int getWidth() const;
    int getHeight() const;
    CellType getCell(int x, int y) const;

private:
    int width, height;
    std::vector<std::vector<CellType>> cells;
};

#endif
