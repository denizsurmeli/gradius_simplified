#include "ShootingEnemyShip.h"


ShootingEnemyShip::ShootingEnemyShip():EnemyShip((SpaceObjectConstants::SPACE_X - ShootingEnemyShipConstants::DIM_X), (rand() % (SpaceObjectConstants::SPACE_Y - ShootingEnemyShipConstants::DIM_Y)), ShootingEnemyShipConstants::DIM_X, ShootingEnemyShipConstants::DIM_Y, new olc::Sprite(RegularEnemyShipConstants::SPRITE_LOCATION), RegularEnemyShipConstants::SPEED) {};

void ShootingEnemyShip::move(float elapsedTime) {};
void ShootingEnemyShip::move(SpaceObject* target, float elapsedTime) {
	//@todo
}