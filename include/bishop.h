#ifndef BISHOP_H
#define BISHOP_H
//Custom headers and forward declaration
#include "piece.h"

//Qt & CPP includes


class Bishop : public Piece
{
private:

public:
    Bishop(Color color);

  //methods
  bool isValidMove(int startRow, int startCol, int endRow, int endCol,Square* board[][8]) const override;
  std::string getSymbol() const override;
  PieceType getType() const override;
};

#endif // BISHOP_H
