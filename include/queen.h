#ifndef QUEEN_H
#define QUEEN_H
//Custom headers and forward declaration
#include "piece.h"

//Qt & CPP includes


class Queen : public Piece
{
private:

public:
    Queen(Color color);

  //methods
  bool isValidMove(int startRow, int startCol, int endRow, int endCol,Square* board[][8]) const override;
  std::string getSymbol() const override;
};

#endif // QUEEN_H
