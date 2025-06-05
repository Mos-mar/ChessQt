//Custom headers and forward declaration
#include "king.h"
#include "square.h"

King::King(Color color) : Piece(color)
{

}

bool King::isValidMove(int startRow, int startCol, int endRow, int endCol, Square *board[][8]) const
{
  if(!Piece::isWithingGrid(endRow,endCol)) return false;

  int rowMovement = abs(endRow - startRow);
  int colMovement = abs(endCol - startCol);

  if (rowMovement > 1 || colMovement > 1)
  {
    return false;
  }

  if(
     board[endRow][endCol]->getPiece() != nullptr &&
     board[endRow][endCol]->getPiece()->getColor() == this->getColor()
     )
  {
     return false;
  }
  return true;
}

std::string King::getSymbol() const
{
 return (getColor() == Color::WHITE) ? "K" : "k";
}
