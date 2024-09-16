#pragma once // Prevent multiple inclusions of this header file
#include <vector>
#include <raylib.h>

class Grid
{
  public:
    Grid();           // Constructor to initialize the grid
    void Initialize();// Function to initialize/reset grid values
    void Print();     // Function to print grid to console (for debugging)
    void Draw();      // Function to render the grid visually in the window
    int grid[20][10]; // Fixed-size grid of 20 rows and 10 columns

  private:
    std::vector<Color> GetCellColors(); // Helper to define colors for grid cells
    int numRows;     // Number of rows in the grid
    int numCols;     // Number of columns in the grid
    int cellSize;    // Size of each cell in pixels
    std::vector<Color> colors; // Color palette for different grid cell values
};
