#include "ShootingEnemyShip.h"


ShootingEnemyShip::ShootingEnemyShip() :EnemyShip((SpaceObjectConstants::SPACE_X - ShootingEnemyShipConstants::DIM_X), (rand() % (SpaceObjectConstants::SPACE_Y - ShootingEnemyShipConstants::DIM_Y)), ShootingEnemyShipConstants::DIM_X, ShootingEnemyShipConstants::DIM_Y, new olc::Sprite(ShootingEnemyShipConstants::SPRITE_LOCATION), ShootingEnemyShipConstants::SPEED), hitCount{ ShootingEnemyShipConstants::LIFE } {};


void ShootingEnemyShip::move(SpaceObject* target, float elapsedTime) {
	//@todo
}