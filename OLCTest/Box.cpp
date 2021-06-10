#include "Box.h"
#include "SpaceObject.h"
#include "SpaceGame.h"
#include "olcSimpleEngine.h"

/*
	Constructor implementation
*/
Box::Box() :SpaceObject((rand() % (SpaceGameConstants::DIM_X - BoxConstants::DIM_X)), (rand() % (SpaceGameConstants::DIM_Y - BoxConstants::DIM_Y)), BoxConstants::DIM_X, BoxConstants::DIM_Y, new olc::Sprite("Sprites/box.png")) {
}

/*
	Checks coordinates for whether the mouse clicked on it or not
	@param x: x-coordinate of the cursor
	@param y: y-coordinate of the cursor
	@return boolean true if clicked false otherwise
*/
bool Box::checkMouseClick(int x, int y) {
	//Collision(inclusion) logic
	if (x >= this->xPosition && x <= this->xPosition + this->dimX &&
		y >= this->yPosition && y <= this->yPosition + this->dimY) {
		return true;
	}return false;
}