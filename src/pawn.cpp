//Custom headers and forward declaration
#include "pawn.h"
#include "square.h"

//Qt & CPP includes


Pawn::Pawn(Color color) : Piece(color)
{
}

bool Pawn::isFirstMove(int startRow) const
{
    return ((getColor() == Color::WHITE && startRow == 6) || (getColor() == Color::BLACK && startRow == 1));
}

bool Pawn::isValidMove(int startRow, int startCol, int endRow, int endCol, Square* board[][8]) const
{
    int rowMovement = endRow - startRow;
    int colMovement = endCol - startCol;

    int direction = (getColor() == Color::WHITE) ?  -1 : 1;

    //can only move straight forward if no enemy piece present diagonally
    if(colMovement !=0 && board[endRow][endCol]->getPiece() == nullptr)
    {
        return false;
    }

    //to be able to move forward if no piece in front
    if(rowMovement == direction && board[endRow][endCol]->getPiece() == nullptr)
    {
       return true;
    }

    //to be able to move diagonally if enemy piece
    if(board[endRow][endCol]->getPiece())
    {
        if(board[endRow][endCol]->getPiece()->getColor() != board[startRow][startCol]->getPiece()->getColor())
        {
            return true;
        }
    }

    if(
         isFirstMove(startRow) &&
         rowMovement == (2*direction) &&
         board[startRow + direction][startCol]->getPiece() == nullptr &&
         board[endRow][endCol]->getPiece() == nullptr
      ){
     return true;
    }
return false;
}

std::string Pawn::getSymbol() const
{
    return this->getColor() == Color::WHITE ? "P" : "p"; //console uses P and p , we will need QPixmap for png files for the UI
}

PieceType Pawn::getType() const
{
 return PieceType::PAWN;
}
