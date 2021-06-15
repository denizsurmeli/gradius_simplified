#pragma once
#include "Asteroid.h"
#include <string>

namespace RegularAsteroidConstants {
    constexpr auto DIM_X = 30;
    constexpr auto DIM_Y = 27;
    constexpr auto SPEED = 75;
    constexpr auto SPRITE_LOCATION = "Sprites/asteroid.png";

}
class RegularAsteroid :
    public Asteroid
{
public:
    RegularAsteroid();
};

