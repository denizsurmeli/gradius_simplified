#include "StrongBullet.h"
#include "Bullet.h"
#include "MovingSpaceObject.h"
#include "SpaceObject.h"
#include <vector>




StrongBullet::StrongBullet(MovingSpaceObject* refPoint): Bullet(refPoint, new olc::Sprite(StrongBulletConstants::SPRITE_LOCATION), StrongBulletConstants::SPEED) {};

void StrongBullet::move(double elapsedTime) {
	this->xPosition += this->speed * elapsedTime;
}


void StrongBullet::nearbyEnemies(std::vector<SpaceObject*> possibleTargets) {};