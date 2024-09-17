#pragma once
#include <raylib.h>
#include <vector>

// Defining color constants for different elements on the grid
// Each Color is represented by four values (R, G, B, A).

extern const Color darkGrey; // Represents empty cells
extern const Color green;    // Represents value 1
extern const Color red;      // Represents value 2
extern const Color orange;   // Represents value 3
extern const Color yellow;   // Represents value 4
extern const Color purple;   // Represents value 5
extern const Color cyan;     // Represents value 6
extern const Color blue;     // Represents value 7

// Function to return a vector containing all defined colors
// Useful for accessing the palette corresponding to grid values
std::vector<Color> GetCellColors();
