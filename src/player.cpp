//Custom headers and forward declaration
#include "player.h"

Player::Player(Color color) : color(color)
{
}

Color Player::get_color()
{
  return color;
}
