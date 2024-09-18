#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EvenTriggered(double interval)
{
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime >= interval)
  {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main()
{
    InitWindow(300, 600, "Tetris RayLib"); // Initialize window with width 300, height 600, and title "Tetris RayLib"
    SetTargetFPS(60); // Set the target FPS to 60 for smooth gameplay
    Color darkBlue = {44, 44, 127, 255}; // Custom dark blue background color

    Game game = Game();
    
    while (!WindowShouldClose()) // Main game loop - runs while the window is not closed
    {
        game.HandleInput();
        if(EvenTriggered(0.2))
        {
          game.MoveBlockDown();
        }
        BeginDrawing(); // Begin rendering
        ClearBackground(darkBlue); // Clear the background with a dark blue color
        game.Draw();
        EndDrawing(); // Finish rendering
    }

    CloseWindow(); // Cleanup resources and close the game window
    return 0;
}
