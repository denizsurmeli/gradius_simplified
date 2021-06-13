#include "Bullet.h"
#include "MovingSpaceObject.h"
#include <vector>




Bullet::Bullet(MovingSpaceObject* refPoint, olc::Sprite* sprite, double speed, Direction direction) :MovingSpaceObject(refPoint->getX() + BulletConstants::DIM_X, refPoint->getY()+ BulletConstants::DIM_Y, dimX, dimY, sprite, speed), direction{ direction } {  }


void Bullet::move(float elapsedTime)
{
	if (this->direction == Direction::PX) {
		this->xPosition += this->speed * elapsedTime;

	}if (this->direction == Direction::NX) {
		this->xPosition -= this->speed * elapsedTime;
	}
}
;

