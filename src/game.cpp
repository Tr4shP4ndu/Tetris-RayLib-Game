/*
This file contains the main logic for the Tetris game. It initializes the game, manages the game state, handles player input, moves blocks, rotates blocks, checks for collisions, and updates the score.

Constructor (Game::Game): Initializes game elements like the grid, blocks, sounds, and music.
Destructor (Game::~Game): Unloads sounds and closes the audio device.
HandleInput: Reads the player's input (e.g., moving the block left/right, rotating it).
MoveBlock...: Functions that move the current block left, right, or down.
RotateBlock: Rotates the block, checks if it's out of bounds, and reverts if necessary.
LockBlock: Locks the block into place when it can no longer move down.
GetRandomBlock: Chooses a random block and ensures there are no repeats until all blocks have been used.
BlockFits/IsBlockOutside: Check whether the block is valid in its current position.
*/

#include "game.h"
#include <random>

Game::Game()
{
  grid = Grid();  // Initializes the game grid
  blocks = GetAllBlocks();  // Retrieves all Tetris blocks
  currentBlock = GetRandomBlock();  // Sets the current block to a random block
  nextBlock = GetRandomBlock();  // Sets the next block to a random block
  gameOver = false;  // Initializes the gameOver flag to false
  score = 0;  // Initializes the score to 0
  InitAudioDevice();  // Initializes the audio device for playing sounds
  music = LoadMusicStream("sounds/music.mp3");  // Loads the background music
  PlayMusicStream(music);  // Starts playing the background music
  rotateSound = LoadSound("sounds/rotate.mp3");  // Loads the rotate sound effect
  clearSound = LoadSound("sounds/clear.mp3");  // Loads the clear line sound effect
}

Game::~Game()
{
  UnloadSound(rotateSound);
  UnloadSound(clearSound);
  UnloadMusicStream(music);
  CloseAudioDevice();
}

Block Game::GetRandomBlock()
{
  if(blocks.empty())
  {
    blocks = GetAllBlocks();
  }
  int randomIndex = rand() % blocks.size();
  Block block = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);
  return block;

}

std::vector<Block> Game::GetAllBlocks()
{
  return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
  grid.Draw();
  currentBlock.Draw(11, 11);
  switch(nextBlock.id)
  {
    case 3:
        nextBlock.Draw(255, 290);
        break;
    case 4:
        nextBlock.Draw(255, 280);
        break;
    default:
        nextBlock.Draw(270, 270);
        break;
  }

}

void Game::HandleInput()
{
  int keyPressed = GetKeyPressed();
  if(gameOver && keyPressed != 0)
  {
    gameOver = false;
    Reset();
  }
  switch(keyPressed)
  {
    case KEY_LEFT:
      MoveBlockLeft();
      break;
    case KEY_RIGHT:
      MoveBlockRight();
      break;
    case KEY_DOWN:
      MoveBlockDown();
      UpdateScore(0, 1);
      break;
    case KEY_UP:
      RotateBlock();
      break;
  }
}

void Game::MoveBlockLeft()
{
  if(!gameOver)
  {
    currentBlock.Move(0, -1);
    if(IsBlockOutside() || BlockFits() == false)
    {
      currentBlock.Move(0, 1);
    }
  }
}

void Game::MoveBlockRight()
{
  if(!gameOver)
  {
    currentBlock.Move(0, 1);
    if(IsBlockOutside() || BlockFits() == false)
    {
      currentBlock.Move(0, -1);
    }
  }
}

void Game::MoveBlockDown()
{
  if(!gameOver)
  {
    currentBlock.Move(1, 0);
    if(IsBlockOutside() || BlockFits() == false)
    {
      currentBlock.Move(-1, 0);
      LockBlock();
    }
  }
}

bool Game::IsBlockOutside()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for(Position item: tiles)
  {
      if(grid.IsCellOutside(item.row, item.column))
      {
        return true;
      }   
  }
  return false;
}

void Game::RotateBlock()
{
  if(!gameOver)
  {
    currentBlock.Rotate();
    if(IsBlockOutside() || BlockFits() == false)
    {
      currentBlock.UndoRotation();
    }
    else
    {
      PlaySound(rotateSound);
    }
  }
}

void Game::LockBlock()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for(Position item: tiles)
  {
    grid.grid[item.row][item.column] = currentBlock.id;

  }
  currentBlock = nextBlock;
  if(BlockFits() == false)
  {
    gameOver = true;
  }
  nextBlock = GetRandomBlock();
  int rowsCleared = grid.ClearFullRows();
  if(rowsCleared > 0)
  {
    PlaySound(clearSound);
    UpdateScore(rowsCleared, 0);
  }
}

bool Game::BlockFits()
{
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for(Position item: tiles)
  {
    if(grid.IsCellEmpty(item.row, item.column) == false)
    {
      return false;
    }
  }
  return true;
}

void Game::Reset()
{
  grid.Initialize();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  score = 0;
}

void Game::UpdateScore(int LinesCleared, int moveDownPoints)
{
  switch(LinesCleared)
  {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
  }
  score += moveDownPoints;
}
