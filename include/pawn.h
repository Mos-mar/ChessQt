#ifndef PAWN_H
#define PAWN_H

//Custom headers and forward declaration
#include "piece.h"

//Qt & CPP includes

class Pawn : public Piece
{
private:
    bool isFirstMove(int startRow) const;
public:
    Pawn(Color color);

  //methods
  bool isValidMove(int startRow, int startCol, int endRow, int endCol,Square* board[][8]) const override;
  std::string getSymbol() const override;
  PieceType getType() const override;

};

#endif // PAWN_H
