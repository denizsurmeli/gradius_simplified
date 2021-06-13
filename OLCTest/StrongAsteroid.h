#pragma once
#include "Asteroid.h"

namespace StrongAsteroidConstants {
    constexpr auto DIM_X = 30;
    constexpr auto DIM_Y = 25;
    constexpr auto SPEED = 20;
    constexpr auto SPRITE_LOCATION = "Sprites/asteroid.png";
    constexpr auto LIFE = 3;
}
class StrongAsteroid :
    public Asteroid
{
private:
    int hitCount;
public:
    StrongAsteroid();
    void reduceHealth();
    bool isDead();
};

