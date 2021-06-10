#pragma once
#include "MovingSpaceObject.h"
#include "olcSimpleEngine.h"
class EnemyShip :
    public MovingSpaceObject
{
public:
    EnemyShip(int x, int y, double dimX, double dimY, olc::Sprite* sprite, double speed);
};

