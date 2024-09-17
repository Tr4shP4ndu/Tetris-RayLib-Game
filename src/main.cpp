#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main()
{
    InitWindow(300, 600, "Tetris RayLib"); // Initialize window with width 300, height 600, and title "Tetris RayLib"
    SetTargetFPS(60); // Set the target FPS to 60 to maintain consistent performance
    Color darkBlue = {44, 44, 127, 255}; // Background color set to a custom dark blue

    Grid grid = Grid(); // Create a Grid object
    // Manually set a few cells in the grid for testing
    // grid.grid[0][0] = 1;
    // grid.grid[3][5] = 4;
    // grid.grid[17][8] = 7;
    grid.Print(); // Print the current state of the grid to the console

    ZBlock block = ZBlock();

    while (!WindowShouldClose()) // Main game loop - runs while the window is not closed
    {
        BeginDrawing(); // Start drawing on the window
        ClearBackground(darkBlue); // Clear the background with the dark blue color
        grid.Draw();// Draw the grid
        block.Draw();
        EndDrawing();// End the drawing phase
    }
    CloseWindow();// Close the window and clean up resources when the game ends
}
