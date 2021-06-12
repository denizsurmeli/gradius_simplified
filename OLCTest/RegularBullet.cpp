#include "RegularBullet.h"
#include "Bullet.h"
#include "SpaceObject.h"
#include "MovingSpaceObject.h"

RegularBullet::RegularBullet(MovingSpaceObject* refPoint) : Bullet(refPoint, new olc::Sprite(RegularBulletConstants::SPRITE_LOCATION), RegularBulletConstants::SPEED) {};

void RegularBullet::move(double elapsedTime) {
	this->xPosition += this->speed * elapsedTime;
}