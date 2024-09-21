#include <raylib.h>
#include "game.h"
#include "colors.h"

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
    InitWindow(500, 620, "Tetris RayLib"); // Initialize window with width 300, height 600, and title "Tetris RayLib"
    SetTargetFPS(60); // Set the target FPS to 60 for smooth gameplay

    Font font = LoadFontEx("font/monogram.ttf", 64, 0, 0);

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
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
          DrawTextEx(font, "GAME OVER!", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing(); // Finish rendering
    }

    CloseWindow(); // Cleanup resources and close the game window
    return 0;
}
