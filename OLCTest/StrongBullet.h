#pragma once
#include "Bullet.h"
#include "MovingSpaceObject.h"
#include "SpaceObject.h"
#include <vector>



namespace StrongBulletConstants {
    constexpr auto SPEED = 250;
    constexpr auto SPRITE_LOCATION = "Sprites/rbullet.png"; //@todo: change
}


class StrongBullet :
    public Bullet
{
private:
    double timestamp;
public:
    StrongBullet(MovingSpaceObject* refPoint,double timestamp);
    void nearbyEnemies(std::vector<SpaceObject*> possibleTargets);

};

