#ifndef MOVEMENTUTIL_H
#define MOVEMENTUTIL_H

//Custom headers and forward declaration
#include "piece.h"
#include "square.h"

//Qt & CPP includes


class MovementUtil{
public:
      //methods
    static bool isValidStraightMove(
           int startRow, int startCol,
           int endRow, int endCol,
           Color color,
           Square* board[][8]
       );
    static bool isValidDiagonalMove(
            int startRow, int startCol,
            int endRow, int endCol,
            Color color,
            Square* board[][8]
        );
};
#endif // MOVEMENTUTIL_H
