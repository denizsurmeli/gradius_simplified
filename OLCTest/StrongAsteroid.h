#pragma once
#include "Asteroid.h"

namespace StrongAsteroidConstants {
    constexpr auto DIM_X = 32;
    constexpr auto DIM_Y = 27;
    constexpr auto SPEED = 10;
    constexpr auto SPRITE_LOCATION = "Sprites/strongAsteroid.png";
    constexpr auto LIFE = 3;
}
class StrongAsteroid :
    public Asteroid
{
private:
    int hitCount;
public:
    StrongAsteroid();
    void move(float elapsedTime) override;
    void reduceHealth();
    bool isDead();
};

