#include "position.h"

// Constructor definition for Position class
Position::Position(int row, int column) // Initializes the row and column members with the given values
{
    this->row = row; // 'this->' is not necessary here unless you want to emphasize that
    this->column = column; // you're referring to the member variables of the class.
}
