#include "ShootingEnemyShip.h"


ShootingEnemyShip::ShootingEnemyShip() :EnemyShip((SpaceObjectConstants::SPACE_X - ShootingEnemyShipConstants::DIM_X), (rand() % (SpaceObjectConstants::SPACE_Y - ShootingEnemyShipConstants::DIM_Y)), ShootingEnemyShipConstants::DIM_X, ShootingEnemyShipConstants::DIM_Y, new olc::Sprite(ShootingEnemyShipConstants::SPRITE_LOCATION), ShootingEnemyShipConstants::SPEED), hitCount{ 0 }, lastFire{ 0 }, bulletCount{ 0 } {};



void ShootingEnemyShip::move(SpaceObject* target, float elapsedTime) {
	double dv = (this->calculateDistance(target) / (this->speed)) + 2;
	if (this->xPosition <= 0) {
		this->xPosition -= this->speed * elapsedTime * 8;
	}

	if (this->yPosition - target->getY() > 0) {
		this->yPosition -= dv * elapsedTime;
	}
	if (this->yPosition - target->getY() < 0) {
		this->yPosition += dv * elapsedTime * 8;
	}
	this->xPosition -= this->speed * elapsedTime;


}

RegularBullet* ShootingEnemyShip::fireBullet(double timeNow)
{

	if (this->canFire(timeNow)) {
		this->lastFire = timeNow;
		this->bulletCount++;
		return new RegularBullet(this,Direction::NX);
	}
	return nullptr;
}

void ShootingEnemyShip::reduceHealth()
{
	this->hitCount++;
}

void ShootingEnemyShip::reduceCount()
{
	if (this->bulletCount >= 1) {
		this->bulletCount--;
	}
	else {
		this->bulletCount = 0;
	}
}

bool ShootingEnemyShip::isDead() {
	return this->hitCount == ShootingEnemyShipConstants::LIFE;
}

bool ShootingEnemyShip::canFire(double timeNow)
{

	return timeNow - this->lastFire >= ShootingEnemyShipConstants::REGEN_BULLET && this->bulletCount < ShootingEnemyShipConstants::MAX_BULLET_COUNT;
}
