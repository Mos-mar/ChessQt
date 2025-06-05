//Custom headers and forward declaration
#include "bishop.h"
#include "movementUtil.h"

Bishop::Bishop(Color color) : Piece(color)
{

}

bool Bishop::isValidMove(int startRow, int startCol, int endRow, int endCol, Square *board[][8]) const
{
  return MovementUtil::isValidDiagonalMove(startRow,startCol,endRow,endCol,this->getColor(),board);
}

std::string Bishop::getSymbol() const
{
    return (this->getColor() == Color::WHITE) ? "B" : "b";
}

PieceType Bishop::getType() const
{
 return PieceType::BISHOP;
}
