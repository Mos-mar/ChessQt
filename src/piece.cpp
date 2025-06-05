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

QString Piece::getImagePath() const
{
  QString color = this->getColor() == Color::WHITE ? "white" : "black";

  QString name = "";
  switch (this->getType()) {
  case PieceType::PAWN : name = "pawn"; break;
  case PieceType::BISHOP : name = "bishop"; break;
  case PieceType::KING : name = "king"; break;
  case PieceType::KNIGHT : name = "knight"; break;
  case PieceType::QUEEN : name = "queen"; break;
  case PieceType::ROOK : name = "rook"; break;
  }
  return QString(":/images/%1-%2.png").arg(color,name);
}
