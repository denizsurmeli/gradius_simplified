#include "Ship.h"
#include "SpaceObject.h"

/*
	Constructor for the Ship class
	@return Ship
*/
Ship::Ship() : MovingSpaceObject(SpaceObjectConstants::SPACE_X / 2, SpaceObjectConstants::SPACE_Y / 2, ShipConstants::DIM_X, ShipConstants::DIM_Y, new olc::Sprite("Sprites/spaceship.png"), ShipConstants::SPEED), canFire{ true }, canUseNuclear{ false }, fireType{ ShipConstants::FireType::Regular}, hitCount{ 0 } {
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


