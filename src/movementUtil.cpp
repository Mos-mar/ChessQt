//Custom headers and forward declaration
#include "movementUtil.h"

//Qt & CPP includes

bool MovementUtil::isValidStraightMove(int startRow, int startCol, int endRow, int endCol, Color color, Square *board[][8])
{
  if(!Piece::isWithingGrid(endRow,endCol)) return false;

  int rowMovement = std::abs(endRow - startRow);
  int colMovement = std::abs(endCol - startCol);

  if((rowMovement != 0 && colMovement != 0) || (rowMovement == 0 && colMovement == 0) )
  {
      return false;
  }else{
     int rowIncrement = (endRow > startRow) ? 1 : -1;
     int colIncrement = (endCol > startCol) ? 1 : -1;

     if(rowMovement == 0){
         int y = startCol + colIncrement;
         while(y != endCol)
         {
             if(board[startRow][y]->getPiece() != nullptr)
             {
                 return false;
             }
             y += colIncrement;
         }
     }else{
         int x = startRow + rowIncrement;
         while(x != endRow)
         {
             if(board[x][startCol]->getPiece() != nullptr)
             {
                 return false;
             }
             x += rowIncrement;
         }
     }
     if(board[endRow][endCol]->getPiece() != nullptr &&
        board[endRow][endCol]->getPiece()->getColor() == color){
         return false;
     }
     return true;
  }

}

bool MovementUtil::isValidDiagonalMove(int startRow, int startCol, int endRow, int endCol, Color color, Square *board[][8])
{
    if(!Piece::isWithingGrid(endRow,endCol)) return false;

  int rowMovement = std::abs(endRow - startRow);
  int colMovement = std::abs(endCol - startCol);

  if(rowMovement == 0 || colMovement == 0) return false;

  if(rowMovement == colMovement)
  {
      int rowIncrement = (endRow > startRow) ? 1 : -1;
      int colIncrement = (endCol > startCol) ? 1 : -1;

      int x = startRow + rowIncrement;
      int y = startCol + colIncrement;

      while( x != endRow && y != endCol)
      {
          if(board[x][y]->getPiece() != nullptr)
          {
              return false;
          }
          x += rowIncrement;
          y += colIncrement;
      }
      if(
         board[endRow][endCol]->getPiece() != nullptr &&
         board[endRow][endCol]->getPiece()->getColor() == color) {
         return false; // friendly piece at destination
      }
      return true;
  }else{

      return false; // not diagonal
  }
}


