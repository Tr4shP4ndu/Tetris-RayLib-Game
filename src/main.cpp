#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main()
{
    InitWindow(300, 600, "Tetris RayLib"); // Initialize window with width 300, height 600, and title "Tetris RayLib"
    SetTargetFPS(60); // Set the target FPS to 60 for smooth gameplay
    Color darkBlue = {44, 44, 127, 255}; // Custom dark blue background color

    Grid grid; // Create a Grid object that manages the game grid
    grid.Print(); // Output initial grid state (for debugging)
    ZBlock block; // Create a ZBlock object (for testing block drawing)
    block.Move(4,3);

    
    while (!WindowShouldClose()) // Main game loop - runs while the window is not closed
    {
        BeginDrawing(); // Begin rendering
        ClearBackground(darkBlue); // Clear the background with a dark blue color
        grid.Draw(); // Draw the grid and the current block
        block.Draw();
        EndDrawing(); // Finish rendering
    }

    CloseWindow(); // Cleanup resources and close the game window
    return 0;
}
