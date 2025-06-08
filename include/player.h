#ifndef PLAYER_H
#define PLAYER_H

//Custom headers and forward declaration
#include "color.h"

class Player {
private:
    Color color;

public:
    Player(Color color);

    Color get_color();
};
#endif // PLAYER_H
