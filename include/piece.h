#ifndef PIECE_H
#define PIECE_H

//Custom headers and forward declaration
#include "color.h"
class Square;


//Qt & CPP includes
#include <QDebug>
#include <iostream>
#include <memory>




class Piece
{
public:
    Piece(Color color);
    virtual ~Piece();
    Color color;

    //Methods
    virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol, Square* board[][8]) const = 0;
    virtual std::string getSymbol() const = 0;
    Color getColor() const;
    static bool isWithingGrid(int endRow, int endCol);

};

#endif // PIECE_H
