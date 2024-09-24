#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

// Class representing a block on a grid that consists of multiple cells
class Block // Each block has a unique ID, rotation state, and uses a color from a palette
{
  public:
    Block(); // Constructor initializes block attributes (size, rotation state, color palette)
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int id; // ID representing the type of block, corresponding to a color in the palette
    // A map that holds different rotation states of the block
    // Each key in the map corresponds to a rotation state (0, 90, 180, etc.)
    std::map<int, std::vector<Position>> cells; // The value is a vector of Positions representing the block's cells

  private:
    int cellSize; // Size of each cell in the block
    int rotationState; // Current rotation state of the block
    std::vector<Color> colors; // Vector of colors corresponding to block IDs, loaded from the palette
    int rowOffset; // Offset for each row in the block
    int columnOffset; // Offset for each column in the block
};
