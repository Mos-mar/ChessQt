//Custom headers and forward declaration
#include "knight.h"
#include "square.h"



//Qt & CPP includes

Knight::Knight(Color color) : Piece(color)
{
}

bool Knight::isValidMove(int startRow, int startCol, int endRow, int endCol, Square *board[][8]) const
{
    int rowMovement = std::abs(endRow - startRow);
    int colMovement = std::abs(endCol - startCol);

    if((rowMovement == 2 && colMovement == 1 )|| (rowMovement == 1 && colMovement == 2))
    {
        if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getPiece()->getColor()==  this->getColor())
        {
            return false;
        }
            return true;
    }
    return false;
}

std::string Knight::getSymbol() const
{
    return this->getColor() == Color::WHITE ? "N" : "n";
}

PieceType Knight::getType() const
{
 return PieceType::KNIGHT;
}
