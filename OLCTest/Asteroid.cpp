#include "Asteroid.h"
#include "MovingSpaceObject.h";
#include "SpaceObject.h";

Asteroid::Asteroid(int dimX, int dimY, olc::Sprite* sprite, double speed) :MovingSpaceObject(SpaceObjectConstants::SPACE_X - dimX, (rand() % (SpaceObjectConstants::SPACE_Y - dimY)), dimX, dimY, sprite, speed) {};

void Asteroid::move(float elapsedTime) {
	if (this->xPosition <= 0) {
		this->xPosition -= 1;
	}
	this->xPosition -= this->speed * elapsedTime;
}