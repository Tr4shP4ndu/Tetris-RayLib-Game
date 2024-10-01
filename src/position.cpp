/*
This file defines the Position class, which represents the position of a block in terms of row and column. It stores the row and column values as public members.
*/

#include "position.h"

// Constructor definition for Position class
Position::Position(int row, int column) // Initializes the row and column members with the given values
{
    this->row = row; // 'this->' is not necessary here unless you want to emphasize that
    this->column = column; // you're referring to the member variables of the class.
}
