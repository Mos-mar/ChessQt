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
    void setPiece(std::unique_ptr<Piece> new_piece); //square takes ownership of the piece
    Piece* getPiece(); //just look/peek at the piece no ownership
    std::unique_ptr<Piece>& getPiecePtr();  //to use with setPiece to be able to use the reference of unique_ptr to move ownership

};

#endif // SQUARE_H
