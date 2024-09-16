#include <raylib.h>
#include "grid.h"


int main()
{
    InitWindow(300, 600, "Tetris RayLib"); //initialize window

    SetTargetFPS(60); // Setting Window of Game 60fps else it's goes above and might crash

    Color darkBlue = {44, 44, 127, 255}; //bg colour to Dark Blue

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.grid[3][5] = 4;
    grid.grid[17][8] = 7;
    grid.Print();

    while(WindowShouldClose() == false) // While Loop for when window is open
    {
      BeginDrawing();
      
      ClearBackground(darkBlue);
      grid.Draw();

      EndDrawing();
    }

    CloseWindow();
}
