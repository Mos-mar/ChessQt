#ifndef SQUARE_H
#define SQUARE_H

//Custom headers and forward declaration
#include "color.h"
class Piece;



//Qt & CPP includes
#include <memory>




class Square
{
public:
    Color color;
    std::unique_ptr<Piece> piece;

    Square(Color color);

    //methods
    void setPiece(std::unique_ptr<Piece> new_piece);
    Piece* getPiece();

};

#endif // SQUARE_H
