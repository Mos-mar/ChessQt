#ifndef KNIGHT_H
#define KNIGHT_H

//Custom headers and forward declaration
#include "piece.h"

//Qt & CPP includes


class Knight : public Piece
{
private:

public:
    Knight(Color color);

  //methods
  bool isValidMove(int startRow, int startCol, int endRow, int endCol,Square* board[][8]) const override;
  std::string getSymbol() const override;
};

#endif // KNIGHT_H
