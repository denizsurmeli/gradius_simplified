#pragma once
#include "EnemyShip.h"
#include "RegularBullet.h"
#include "StrongBullet.h"
#include "Bullet.h"

namespace ShootingEnemyShipConstants {
    constexpr auto DIM_X = 30;
    constexpr auto DIM_Y = 40;
    constexpr auto SPEED = 15;
    constexpr auto REGEN_BULLET = 2;
    constexpr auto MAX_BULLET_COUNT = 3;
    constexpr auto SPRITE_LOCATION = "Sprites/shootingEnemy.png"; //@todo->change these
    constexpr auto LIFE = 3;
}

class ShootingEnemyShip :
    public EnemyShip
{
private:
    int hitCount;
    double lastFire;
    int bulletCount;
public:
    ShootingEnemyShip();
    void move(SpaceObject* target, float elapsedTime);
    RegularBullet* fireBullet(double timeNow);

    void reduceHealth();
    void reduceCount();
    bool isDead();
    bool canFire(double timeNow);
};

