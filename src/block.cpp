#include "block.h"

// Constructor for Block class
Block::Block() // Initializes cell size, rotation state, and loads the color palette from GetCellColors
{
    cellSize = 30;             // Set the size of each individual cell in the block
    rotationState = 0;         // Start with default rotation state
    colors = GetCellColors();  // Load the predefined color palette
    rowOffset = 0;
    columnOffset = 0;
}


void Block::Draw(int offsetX, int offsetY) // Draw the block on the grid based on its current rotation state
{
    std::vector<Position> tiles = GetCellPositions(); // Get the positions of the block's cells for the current rotation state
    for(Position item : tiles) // Iterate over each cell (Position) in the block and draw it
    {
        
        DrawRectangle(                     // Draw each cell as a rectangle with a slight border for visual separation
            item.column * cellSize + offsetX,    // X position with a slight offset for the border
            item.row * cellSize + offsetY,       // Y position with a slight offset for the border
            cellSize - 1,                  // Width of the cell, leaving space for the border
            cellSize - 1,                  // Height of the cell, leaving space for the border
            colors[id]                     // Assign the color based on the block's ID
        );
    }
}

void Block::Move(int rows, int columns)
{
  rowOffset += rows;
  columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions()
{
  std::vector<Position> tiles = cells[rotationState];
  std::vector<Position> movedTiles;
  for(Position item: tiles)
  {
    Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}

void Block::Rotate()
{
  rotationState ++;
  if(rotationState == (int)cells.size())
  {
    rotationState = 0;
  }
}

void Block::UndoRotation()
{
  rotationState --;
  if(rotationState == -1)
  {
    rotationState = cells.size() - 1;
  }
}
