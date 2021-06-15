#include "Ship.h"
#include "SpaceObject.h"

/*
	Constructor for the Ship class
	@return Ship
*/
Ship::Ship() : MovingSpaceObject(SpaceObjectConstants::SPACE_X / 2, SpaceObjectConstants::SPACE_Y / 2, ShipConstants::DIM_X, ShipConstants::DIM_Y, new olc::Sprite("Sprites/spaceship.png"), ShipConstants::SPEED), canFire{ true }, canUseNuclear{ false }, fireType{ ShipConstants::FireType::Regular }, hitCount{ 0 }, strongBulletTime{ 0 } {
};

/*
	Movement dynamics of the Ship class
	@param direction:Direction of the movement
	@param elapsedTime: time taken for displacement
*/
void Ship::move(Direction direction, float elapsedTime) {
	//Push A
	if (direction == Direction::NX) {
		if (this->xPosition <= 0) {
			this->xPosition = 0;
		}
		else {
			this->xPosition -= this->speed * elapsedTime;
		}
	}
	//Push W
	if (direction == Direction::NY) {
		if (this->yPosition <= 0) {
			this->yPosition = 0;
		}
		else {
			this->yPosition -= this->speed * elapsedTime;
		}

	}
	//Push D
	if (direction == Direction::PX) {
		if (this->xPosition + this->dimX >= SpaceObjectConstants::SPACE_X) {
			this->xPosition = SpaceObjectConstants::SPACE_X - this->dimX;
		}
		else {
			this->xPosition += this->speed * elapsedTime;
		}
	}
	//Push S
	if (direction == Direction::PY) {
		if (this->yPosition + this->dimY >= SpaceObjectConstants::SPACE_Y) {
			this->yPosition = SpaceObjectConstants::SPACE_Y - this->dimY;
		}
		else {
			this->yPosition += this->speed * elapsedTime;
		}

	}

}

bool Ship::shipCanFire()
{
	return this->canFire;
}

bool Ship::shipCanUseNuclear()
{
	return this->canUseNuclear;
}

bool Ship::isDead()
{
	return this->hitCount >= ShipConstants::LIFE;
}

ShipConstants::FireType Ship::getFireType()
{
	return this->fireType;
}

void Ship::toggleFire()
{
	this->canFire = this->canFire == true ? false : true;
}

void Ship::toggleNuclear()
{
	this->canUseNuclear = this->canUseNuclear ? false : true;
}

void Ship::reduceHealth()
{
	this->hitCount++;
}

void Ship::captureStrongBullet(double timeNow)
{
	if (!(this->fireType == ShipConstants::FireType::Strong)) {
		this->fireType = ShipConstants::FireType::Strong;
		this->strongBulletTime = timeNow;
	}
}


Bullet* Ship::fireBullet(double timeNow) {
	if (timeNow - this->strongBulletTime >= ShipConstants::STR_BULLET_LIFETIME) {
		this->fireType = ShipConstants::FireType::Regular;

	}
	if (this->shipCanFire()) {
		this->toggleFire();
		if (fireType == ShipConstants::FireType::Regular) {
			auto b = new RegularBullet(this,Direction::PX);
			return b;
		}
		if (fireType == ShipConstants::FireType::Strong && timeNow - this->strongBulletTime <= ShipConstants::STR_BULLET_LIFETIME) {
			this->fireType = ShipConstants::FireType::Regular;
			auto b = new StrongBullet(this, Direction::PX);
			return b;
		}
	}
	return nullptr;

}
