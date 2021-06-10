#pragma once
#include "MovingSpaceObject.h"

//Dimensions of ship
namespace ShipConstants {
    constexpr auto DIM_X = 25;
    constexpr auto DIM_Y = 23;
    constexpr auto SPEED = 125;
    constexpr auto LIFE = 3;
    constexpr auto SPRITE_LOCATION = "Sprites/spaceship.png";
}


class Ship :
    public MovingSpaceObject
{
private:
    int hitCount;
    bool canUseNuclear;
    bool canFire;

public:
    Ship();
    void move(Direction direction, float elapsedTime) override;



};

