#include "block.h"

Block::Block()
{
  cellSize = 30;
  rotationState = 0;
  colors = GetCellColors();
}

void Block::Draw()
{
  std::vector<Position> tiles = cells[rotationState];
  for(Position item: tiles)
  {
    DrawRectangle(             // Draw each cell as a colored rectangle, with a slight border
                item.column * cellSize + 1, // X position (with border offset)
                item.row * cellSize + 1,    // Y position (with border offset)
                cellSize - 1,          // Width (leaving border space)
                cellSize - 1,          // Height (leaving border space)
                colors[id]      // Color from the color palette
            );
  }
}
