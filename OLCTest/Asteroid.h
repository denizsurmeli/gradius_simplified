#pragma once
#include "MovingSpaceObject.h"
#include "SpaceObject.h"
class Asteroid :
    public MovingSpaceObject


{
public:
    Asteroid(double dimX, double dimY, olc::Sprite* sprite,double speed);
    explicit void move(float elapsedTime) override;
};

