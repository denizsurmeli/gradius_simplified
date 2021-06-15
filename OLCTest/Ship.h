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
    constexpr auto STR_BULLET_LIFETIME = 5;
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
    double strongBulletTime;
    bool canUseNuclear;
    bool canFire;
    ShipConstants::FireType fireType;
    

public:
    Ship();
    void move(Direction direction, float elapsedTime);
    bool shipCanFire();
    bool shipCanUseNuclear();
    bool isDead();
    ShipConstants::FireType getFireType();
    void toggleFire();
    void toggleNuclear();
    void reduceHealth();

    void captureStrongBullet(double timeNow);
    Bullet* fireBullet(double timeNow);
};

