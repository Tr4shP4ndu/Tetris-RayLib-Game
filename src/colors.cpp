#include "colors.h"

// Define colors as constants with RGBA values.
// The last value (A) is the alpha channel for transparency (255 = fully opaque).

const Color darkGrey = {26, 31, 40, 255}; // Used for empty cells (default background)
const Color green = {47, 230, 23, 255};   // Color for cells with value 1
const Color red = {232, 18, 18, 255};     // Color for cells with value 2
const Color orange = {226, 116, 17, 255}; // Color for cells with value 3
const Color yellow = {237, 234, 4, 255};  // Color for cells with value 4
const Color purple = {166, 0, 247, 255};  // Color for cells with value 5
const Color cyan = {21, 204, 209, 255};   // Color for cells with value 6
const Color blue = {13, 64, 216, 255};    // Color for cells with value 7

// Returns a vector containing all the colors in the order they correspond to grid values.
// This allows easy access to color mapping for cells by their value.
std::vector<Color> GetCellColors()
{
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}
