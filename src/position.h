/*
This header file declares the Position class, which is a utility class that stores the row and column values of a grid cell.
*/

#pragma once

class Position // Class to represent a position on a grid with row and column coordinates
{
  public:
    Position(int row, int column);  // Constructor to initialize the position
    int row;  // Stores the row value
    int column;  // Stores the column value
};
