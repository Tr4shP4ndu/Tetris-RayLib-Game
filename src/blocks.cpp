#include "block.h"
#include "position.h"

// L-shaped Block class derived from Block
class LBlock : public Block
{
  public:
    // Constructor to define the LBlock's rotation states and unique ID
    LBlock()
    {
      id = 1; // Unique ID for the LBlock (used for color)
      
      // Define each rotation state (0, 90, 180, 270 degrees)
      cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
      cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
      cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
      cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
      Move(0, 3);
    }
};

// J-shaped Block class derived from Block
class JBlock : public Block
{
  public:
    // Constructor to define the JBlock's rotation states and unique ID
    JBlock()
    {
      id = 2; // Unique ID for the JBlock
      
      // Define each rotation state (0, 90, 180, 270 degrees)
      cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
      cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
      cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
      cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
      Move(0, 3);
    }
};

// I-shaped Block class derived from Block
class IBlock : public Block
{
  public:
    // Constructor to define the IBlock's rotation states and unique ID
    IBlock()
    {
      id = 3; // Unique ID for the IBlock
      
      // Define each rotation state (0, 90, 180, 270 degrees)
      cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
      cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
      cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
      cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
      Move(-1, 3);
    }
};

// O-shaped Block class derived from Block (no rotation needed)
class OBlock : public Block
{
  public:
    // Constructor to define the OBlock's rotation states and unique ID
    OBlock()
    {
      id = 4; // Unique ID for the OBlock
      
      // The OBlock doesn't rotate, so only one rotation state
      cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
      Move(0, 4);
    }
};

// S-shaped Block class derived from Block
class SBlock : public Block
{
  public:
    // Constructor to define the SBlock's rotation states and unique ID
    SBlock()
    {
      id = 5; // Unique ID for the SBlock
      
      // Define each rotation state (0, 90, 180, 270 degrees)
      cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
      cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
      cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
      cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
      Move(0, 3);
    }
};

// T-shaped Block class derived from Block
class TBlock : public Block
{
  public:
    // Constructor to define the TBlock's rotation states and unique ID
    TBlock()
    {
      id = 6; // Unique ID for the TBlock
      
      // Define each rotation state (0, 90, 180, 270 degrees)
      cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
      cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
      cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
      cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
      Move(0, 3);
    }
};

// Z-shaped Block class derived from Block
class ZBlock : public Block
{
  public:
    // Constructor to define the ZBlock's rotation states and unique ID
    ZBlock()
    {
      id = 7; // Unique ID for the ZBlock
      
      // Define each rotation state (0, 90, 180, 270 degrees)
      cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
      cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
      cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
      cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
      Move(0, 3);
    }
};
