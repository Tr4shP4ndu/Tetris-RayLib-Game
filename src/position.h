#pragma once


class Position // Class to represent a position on a grid with row and column coordinates
{
  public:
    Position(int row, int column); // Constructor to initialize the position with row and column values
    int row;
    int column;
};
