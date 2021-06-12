#include "Bullet.h"
#include "MovingSpaceObject.h"
#include <vector>




Bullet::Bullet(MovingSpaceObject* refPoint, olc::Sprite* sprite, double speed) :MovingSpaceObject(refPoint->getX(), refPoint->getY(), dimX, dimY, sprite, speed) {  }


void Bullet::move(float elapsedTime)
{
	this->xPosition += this->speed * elapsedTime;
}
;

