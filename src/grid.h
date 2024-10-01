/*
This file declares the Grid class, which represents the playing area of the game. It includes methods for managing the grid state, drawing the grid, and checking if certain cells are empty or outside the grid.
*/

#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
  public:
    Grid();  // Constructor to initialize the grid
    void Initialize();  // Resets the grid to an empty state
    void Print();  // Prints the grid to the console (for debugging)
    void Draw();  // Renders the grid on the screen
    bool IsCellOutside(int row, int column);  // Checks if a cell is outside the grid
    bool IsCellEmpty(int row, int column);  // Checks if a cell is empty
    int ClearFullRows();  // Clears rows that are fully filled
    int grid[20][10];  // The actual grid of cells (20 rows by 10 columns)

  private:
    bool IsRollFull(int row);  // Checks if a specific row is full
    void ClearRow(int row);  // Clears a specific row
    void MoveRowDow(int row, int numRows);  // Moves rows down after clearing
    int numRows;  // Number of rows in the grid
    int numCols;  // Number of columns in the grid
    int cellSize;  // Size of each cell in pixels
    std::vector<Color> colors;  // Color palette for cells
};
