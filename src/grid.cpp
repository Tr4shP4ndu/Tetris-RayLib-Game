/*
This file defines the behavior of the game grid. It handles the grid's initialization, rendering, checking if cells are inside the grid, clearing full rows, and moving rows down after a line is cleared.

Grid Initialization: Initializes the grid with empty cells.
Draw: Renders the grid and its colors on the screen.
ClearFullRows: Checks for and clears fully filled rows.
*/
#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows = 20;  // Sets the number of rows in the grid (standard Tetris size)
    numCols = 10;  // Sets the number of columns in the grid (standard Tetris size)
    cellSize = 30;  // Size of each grid cell in pixels
    Initialize();  // Initializes the grid with empty cells
    colors = GetCellColors();  // Loads a palette of colors for grid cells
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
                column * cellSize + 11, // X position
                row * cellSize + 11,    // Y position
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

bool Grid::IsCellEmpty(int row, int column)
{
  if(grid[row][column] == 0)
  {
    return true;
  }
  return false;
}

int Grid::ClearFullRows()
{
  int completed = 0;
  for(int row = numRows-1; row >= 0; row--)
  {
    if(IsRollFull(row))
    {
      ClearRow(row);
      completed++;
    }
    else if(completed > 0)
    {
      MoveRowDow(row, completed);
    }
  }
  return completed;
}

bool Grid::IsRollFull(int row)
{
  for(int column = 0; column < numCols; column++)
  {
    if(grid[row][column] == 0)
    {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row)
{
  for(int column = 0; column < numCols; column++)
  {
    grid[row][column] = 0;
  }
}

void Grid::MoveRowDow(int row, int numRows)
{
  for(int column = 0; column < numCols; column++)
  {
    grid[row + numRows][column] = grid[row][column];
    grid[row][column] = 0;
  }

}
