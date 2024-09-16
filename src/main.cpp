#include <raylib.h>


int main()
{
    InitWindow(300, 600, "Tetris RayLib"); //initialize window

    SetTargetFPS(60); // Setting Window of Game 60fps else it's goes above and might crash

    Color darkBlue = {44, 44, 127, 255}; //bg colour to Dark Blue

    while(WindowShouldClose() == false) // While Loop for when window is open
    {
      BeginDrawing();
      
      ClearBackground(darkBlue);

      EndDrawing();
    }

    CloseWindow();
}
