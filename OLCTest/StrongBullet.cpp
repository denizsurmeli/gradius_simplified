#include "StrongBullet.h"
#include "Bullet.h"
#include "MovingSpaceObject.h"
#include "SpaceObject.h"
#include <vector>




StrongBullet::StrongBullet(MovingSpaceObject* refPoint, double timestamp) : Bullet(refPoint, new olc::Sprite(StrongBulletConstants::SPRITE_LOCATION), StrongBulletConstants::SPEED), timestamp{ timestamp } {};



void StrongBullet::nearbyEnemies(std::vector<SpaceObject*> possibleTargets) {};