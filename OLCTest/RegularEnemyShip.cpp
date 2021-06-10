#include "RegularEnemyShip.h"
#include "SpaceObject.h"
#include "EnemyShip.h"


RegularEnemyShip::RegularEnemyShip() : EnemyShip((SpaceObjectConstants::SPACE_X - RegularEnemyShipConstants::DIM_X), (rand() % (SpaceObjectConstants::SPACE_Y - RegularEnemyShipConstants::DIM_Y)), RegularEnemyShipConstants::DIM_X, RegularEnemyShipConstants::DIM_Y, new olc::Sprite(RegularEnemyShipConstants::SPRITE_LOCATION), RegularEnemyShipConstants::SPEED) {};

void RegularEnemyShip::move(float elapsedTime) {
	if (this->xPosition <= 0) {
		this->xPosition -= this->speed * elapsedTime;
	}
	this->xPosition -= this->speed * elapsedTime;
}

void RegularEnemyShip::move(SpaceObject* target, float elapsedTime) {};

