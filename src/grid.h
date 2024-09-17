#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
  public:
    Grid();           // Constructor to initialize grid
    void Initialize();// Function to reset the grid values
    void Print();     // Output the current grid state to console (for debugging)
    void Draw();      // Render the grid in the window
    int grid[20][10]; // Fixed-size grid for the Tetris game (20 rows by 10 columns)

  private:
    int numRows;      // Number of rows in the grid
    int numCols;      // Number of columns in the grid
    int cellSize;     // Size of each grid cell in pixels
    std::vector<Color> colors; // Color palette for different cell values
};
