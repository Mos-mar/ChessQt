//Custom headers and forward declaration
#include "piece.h"

//Qt & CPP includes

Piece::Piece(Color color) : color(color)
{

}

Piece::~Piece()
{

}

Color Piece::getColor() const
{
  return color;
}

bool Piece::isWithingGrid(int endRow, int endCol)
{
  return 0 <= endRow && endRow <= 7 && 0 <= endCol && endCol <= 7;
}
