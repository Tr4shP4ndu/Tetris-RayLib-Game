#pragma once // this means this is only included once, avoid duplicate deffination
#include <vector>
#include <raylib.h>

class Grid
{
  public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    int grid[20][10]; // Adjust this to handle dynamic sizes if needed

  private:
    std::vector<Color> GetCellColors();
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};
