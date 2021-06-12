#pragma once
#include "MovingSpaceObject.h"
#include "SpaceObject.h"
#include "olcSimpleEngine.h"
#include <vector>
namespace BulletConstants {
    constexpr auto DIM_X = 5;
    constexpr auto DIM_Y = 4;
}

class Bullet :public MovingSpaceObject
{
protected:

public:
	Bullet(MovingSpaceObject* refPoint,olc::Sprite* sprite, double speed);
    void move(float elapsedTime) override;
};

