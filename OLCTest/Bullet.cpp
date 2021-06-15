#include "Bullet.h"
#include "MovingSpaceObject.h"
#include <vector>




Bullet::Bullet(MovingSpaceObject* refPoint, olc::Sprite* sprite, double speed, Direction direction, BulletConstants::BulletType type) :MovingSpaceObject(refPoint->getX() + BulletConstants::DIM_X, refPoint->getY() + BulletConstants::DIM_Y, dimX, dimY, sprite, speed), direction{ direction }, type{ type } {  }


void Bullet::move(float elapsedTime)
{
	if (this->direction == Direction::PX) {
		this->xPosition += this->speed * elapsedTime;

	}if (this->direction == Direction::NX) {
		this->xPosition -= this->speed * elapsedTime;
	}
}
BulletConstants::BulletType Bullet::getType()
{
	return this->type;
}
std::vector<SpaceObject*> Bullet::getNearbyEnemies(std::vector<SpaceObject*> possibleTargets)
{
	std::vector<SpaceObject*> temp{};
	for (auto& obj : possibleTargets) {
		if (obj != nullptr) {
			if (this->calculateDistance(obj) <= BulletConstants::RADIUS) {
				temp.push_back(obj);
			}
		}
		
	}

	return temp;
}
;

