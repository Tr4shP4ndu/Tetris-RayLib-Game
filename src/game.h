/*
This header file declares the Game class, which includes the game's grid, blocks, and functions that handle block movements, rotations, input, and game state.

Public Methods: Exposes methods for drawing, handling input, and moving blocks down.
Private Methods: Includes utility functions like checking if the block fits, resetting the game, or updating the score.
*/

#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
  public:
    Game();  // Constructor to initialize the game
    ~Game();  // Destructor to clean up resources
    void Draw();  // Draws the game elements on the screen
    void HandleInput();  // Handles player input
    void MoveBlockDown();  // Moves the current block downwards
    bool gameOver;  // Game state flag to track if the game is over
    int score;  // Stores the player's score
    Music music;  // Background music

  private:
    Block GetRandomBlock();  // Returns a random block
    std::vector<Block> GetAllBlocks();  // Returns a list of all block types
    bool IsBlockOutside();  // Checks if the block is outside the grid
    void MoveBlockLeft();  // Moves the block left
    void MoveBlockRight();  // Moves the block right
    void RotateBlock();  // Rotates the block
    void LockBlock();  // Locks the block into place when it reaches the bottom
    bool BlockFits();  // Checks if the block fits in its current position
    void Reset();  // Resets the game state
    void UpdateScore(int LinesCleared, int moveDownPoints);  // Updates the score
    Grid grid;  // Represents the game's grid
    std::vector<Block> blocks;  // List of all possible Tetris blocks
    Block currentBlock;  // The current block the player is controlling
    Block nextBlock;  // The next block to appear
    Sound rotateSound;  // Sound effect for rotating blocks
    Sound clearSound;  // Sound effect for clearing lines
};
