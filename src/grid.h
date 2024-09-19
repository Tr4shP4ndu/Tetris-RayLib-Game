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
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
    int grid[20][10]; // Fixed-size grid for the Tetris game (20 rows by 10 columns)

  private:
    bool IsRollFull(int row);
    void ClearRow(int row);
    void MoveRowDow(int row, int numRows);
    int numRows;      // Number of rows in the grid
    int numCols;      // Number of columns in the grid
    int cellSize;     // Size of each grid cell in pixels
    std::vector<Color> colors; // Color palette for different cell values
};
