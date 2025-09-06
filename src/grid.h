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
    void Print() const;  // Prints the grid to the console (for debugging)
    void Draw() const;  // Renders the grid on the screen
    bool IsCellOutside(int row, int column) const;  // Checks if a cell is outside the grid
    bool IsCellEmpty(int row, int column) const;  // Checks if a cell is empty
    int ClearFullRows();  // Clears rows that are fully filled
    int grid[20][10];  // The actual grid of cells (20 rows by 10 columns)

  private:
    bool IsRowFull(int row) const;  // Checks if a specific row is full
    void ClearRow(int row);  // Clears a specific row
    void MoveRowDown(int row, int count);  // Moves rows down after clearing
    const int numRows;  // Number of rows in the grid
    const int numCols;  // Number of columns in the grid
    const int cellSize;  // Size of each cell in pixels
    std::vector<Color> colors;  // Color palette for cells
};
