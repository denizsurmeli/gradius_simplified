#pragma once
#include "MovingSpaceObject.h"
#include "SpaceObject.h"
#include "olcSimpleEngine.h"
#include <vector>
namespace BulletConstants {
    constexpr auto DIM_X = 5;
    constexpr auto DIM_Y = 4;
    constexpr auto RADIUS = 100;
    enum class BulletType {
        Regular = 1,
        Strong = 2
    };
}

class Bullet :public MovingSpaceObject
{
protected:
    Direction direction;
    BulletConstants::BulletType type;
public:
    Bullet(MovingSpaceObject* refPoint, olc::Sprite* sprite, double speed, Direction direction,BulletConstants::BulletType type);
    void move(float elapsedTime) override;
    BulletConstants::BulletType getType();
    std::vector<SpaceObject*> getNearbyEnemies(std::vector<SpaceObject*> possibleTargets);
};
