#ifndef KING_H
#define KING_H


//Custom headers and forward declaration
#include "piece.h"

//Qt & CPP includes


class King : public Piece
{
private:

public:
    King(Color color);

  //methods
  bool isValidMove(int startRow, int startCol, int endRow, int endCol,Square* board[][8]) const override;
  std::string getSymbol() const override;
  PieceType getType() const override;
};



#endif // KING_H
