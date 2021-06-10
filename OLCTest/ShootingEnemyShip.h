#pragma once
#include "EnemyShip.h"

namespace ShootingEnemyShipConstants {
    constexpr auto DIM_X = 27;
    constexpr auto DIM_Y = 25;
    constexpr auto SPEED = 60;
    constexpr auto SPRITE_LOCATION = "Sprites/enemy.png"; //@todo->change these
}

class ShootingEnemyShip :
    public EnemyShip
{

    ShootingEnemyShip();
    void move(float elapsedTime) override;
    void move(SpaceObject* target, float elapsedTime) override;

};

