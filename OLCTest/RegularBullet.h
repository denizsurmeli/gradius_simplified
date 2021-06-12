#pragma once
#include "Bullet.h"
#include "MovingSpaceObject.h"
#include "SpaceObject.h"

namespace RegularBulletConstants {
    constexpr auto SPEED = 200;
    constexpr auto SPRITE_LOCATION = "Sprites/rbullet.png";
}
class RegularBullet :
    public Bullet
{
public:
    RegularBullet(MovingSpaceObject* refPoint);
    void move(double elapsedTime);


};

