#include "colors.h"


const Color darkGrey = {26, 31, 40, 255}; // For empty cells
const Color green = {47, 230, 23, 255};   // For value 1
const Color red = {232, 18, 18, 255};     // For value 2
const Color orange = {226, 116, 17, 255}; // For value 3
const Color yellow = {237, 234, 4, 255};  // For value 4
const Color purple = {166, 0, 247, 255};  // For value 5
const Color cyan = {21, 204, 209, 255};   // For value 6
const Color blue = {13, 64, 216, 255};    // For value 7

std::vector<Color> GetCellColors()
{
  return {darkGrey, green, red, orange, yellow, purple, cyan, blue}; // Return the color palette corresponding to grid values
}
