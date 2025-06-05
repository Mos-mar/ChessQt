//Custom headers and forward declaration
#include "rook.h"
#include "movementUtil.h"

Rook::Rook(Color color) : Piece(color)
{

}

bool Rook::isValidMove(int startRow, int startCol, int endRow, int endCol, Square *board[][8]) const
{
  return MovementUtil::isValidStraightMove(startRow,startCol,endRow,endCol,this->getColor(),board);
}

std::string Rook::getSymbol() const
{
  return (this->getColor() == Color::WHITE) ? "R" : "r";
}
