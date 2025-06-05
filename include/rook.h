#ifndef ROOK_H
#define ROOK_H
//Custom headers and forward declaration
#include "piece.h"

//Qt & CPP includes


class Rook : public Piece
{
private:

public:
    Rook(Color color);

  //methods
  bool isValidMove(int startRow, int startCol, int endRow, int endCol,Square* board[][8]) const override;
  std::string getSymbol() const override;
};

#endif // ROOK_H
