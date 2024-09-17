#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows = 20;  // Standard Tetris grid size (20 rows)
    numCols = 10;  // Standard Tetris grid width (10 columns)
    cellSize = 30; // Each cell is 30x30 pixels
    Initialize();  // Fill the grid with empty cells
    colors = GetCellColors(); // Load the predefined colors
}

void Grid::Initialize()
{
    // Set all grid cells to 0 (empty state)
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
          grid[row][column] = 0;
        }
    }
}

void Grid::Print()
{
    // Print the current grid to console (mainly for debugging)
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    // Render the grid in the window
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column]; // Fetch the current cell's value
            // Draw the cell with the corresponding color from the palette
            DrawRectangle(
                column * cellSize + 1, // X position
                row * cellSize + 1,    // Y position
                cellSize - 1,          // Width (adjusted for border)
                cellSize - 1,          // Height (adjusted for border)
                colors[cellValue]      // Color based on cell value
            );
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
  if(row >= 0 && row < numRows && column >= 0 && column < numCols)
  {
    return false;
  }
  return true;
}
