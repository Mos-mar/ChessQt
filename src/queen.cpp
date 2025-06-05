//Custom headers and forward declaration
#include "queen.h"
#include "movementUtil.h"

Queen::Queen(Color color) : Piece(color)
{

}

bool Queen::isValidMove(int startRow, int startCol, int endRow, int endCol, Square *board[][8]) const
{
  return MovementUtil::isValidStraightMove(startRow,startCol,endRow,endCol,this->getColor(),board) || MovementUtil::isValidDiagonalMove(startRow,startCol,endRow,endCol,this->getColor(),board);
}

std::string Queen::getSymbol() const
{
 return this->getColor() == Color::WHITE ? "Q" : "q";
}
