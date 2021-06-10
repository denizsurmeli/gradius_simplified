#pragma once
#include "EnemyShip.h"
#include "MovingSpaceObject.h"

namespace RegularEnemyShipConstants {
    constexpr auto DIM_X = 27;
    constexpr auto DIM_Y = 25;
    constexpr auto SPEED = 100;
    constexpr auto SPRITE_LOCATION = "Sprites/enemy.png";
}

class RegularEnemyShip :
    public EnemyShip
{

public:
    RegularEnemyShip();
    void move(float elapsedTime) override;
    void move(SpaceObject* target, float elapsedTime) override;


};

