#include "MovingSpaceObject.h"

/*
	Constructor for MovingSpaceObject
	@param x: x-coordinate
	@param y: y-coordinate
	@param d_x: x-dimension
	@param d_y: y-dimension
	@param spriteRef: sprite of the object
	@param speed: speed of the object
	@return MovingSpaceObject
*/
MovingSpaceObject::MovingSpaceObject(int x, int y, double d_x, double d_y, olc::Sprite* spriteRef, double speed) : SpaceObject(x, y, d_x, d_y, spriteRef), speed{ speed } {
}

void MovingSpaceObject::move(Direction direction, float elapsedTime) {
	//total displacement
	auto location_change = this->speed * elapsedTime;
	//Movement logic
	if (direction == Direction::PX) {
		this->xPosition += location_change;
	}
	if (direction == Direction::PY) {
		this->yPosition += location_change;
	}
	if (direction == Direction::NX) {
		this->xPosition -= location_change;
	}
	if (direction == Direction::NY) {
		this->yPosition -= location_change;
	}

}