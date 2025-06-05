//Custom headers and forward declaration
#include "square.h"
#include "piece.h"

//Qt & CPP includes

Square::Square(Color color) : color(color),piece(nullptr)
{

}

void Square::setPiece(std::unique_ptr<Piece> new_piece)
{
    piece = move(new_piece); //square takes ownership of the piece
}

Piece *Square::getPiece()
{
  return piece.get(); //just look at the piece no ownership
}


