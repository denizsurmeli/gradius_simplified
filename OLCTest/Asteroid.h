#pragma once
#include "MovingSpaceObject.h"
#include "SpaceObject.h"
class Asteroid :
    public MovingSpaceObject


{
public:
    Asteroid(int dimX, int dimY, olc::Sprite* sprite,double speed);
    void move(float elapsedTime) override;
};

