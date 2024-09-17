#include "grid.h"
#include <iostream>
#include "colors.h"


Grid::Grid() // Constructor initializes the grid dimensions, cell size, and colors
{
    numRows = 20; // Set number of rows
    numCols = 10; // Set number of columns
    cellSize = 30; // Size of each cell in pixels (30x30)
    Initialize(); // Initialize grid to be empty (filled with 0)
    colors = GetCellColors(); // Load colors that represent different block types
}

void Grid::Initialize() // Initialize the grid by setting all cells to 0 (empty state)
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print()// Print the grid to the console for debugging purposes
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}


void Grid::Draw() // Draw the grid in the window
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column]; // Get the value of the current cell (used as index for colors)
            DrawRectangle(             // Draw each cell as a colored rectangle, with a slight border
                column * cellSize + 1, // X position (with border offset)
                row * cellSize + 1,    // Y position (with border offset)
                cellSize - 1,          // Width (leaving border space)
                cellSize - 1,          // Height (leaving border space)
                colors[cellValue]      // Color from the color palette
            );
        }
    }
}
