#pragma once
#include "MovingSpaceObject.h"
#include "RegularBullet.h"
#include "StrongBullet.h"
#include "Bullet.h"

//Dimensions of ship
namespace ShipConstants {
    constexpr auto DIM_X = 25;
    constexpr auto DIM_Y = 23;
    constexpr auto SPEED = 125;
    constexpr auto LIFE = 3;
    constexpr auto SPRITE_LOCATION = "Sprites/spaceship.png";
    
    enum class FireType {
        Regular = 1,
        Strong = 2
    };
}


class Ship :
    public MovingSpaceObject
{
private:
    int hitCount;
    bool canUseNuclear;
    bool canFire;
    ShipConstants::FireType fireType;
    

public:
    Ship();
    void move(Direction direction, float elapsedTime);
    Bullet* fireBullet();
};

