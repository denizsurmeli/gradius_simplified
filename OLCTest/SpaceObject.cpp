#include "SpaceObject.h"
#include "olcSimpleEngine.h"
#include "SpaceGame.h"


/*
	Constructor implementations
*/
SpaceObject::SpaceObject() : xPosition{ SpaceGameConstants::DIM_X }, yPosition{ SpaceGameConstants::DIM_Y }, dimX{ 0 }, dimY{ 0 }, sprite{ nullptr } {};
SpaceObject::SpaceObject(int x, int y, double d_x, double d_y, olc::Sprite* spriteRef) :xPosition{ x }, yPosition{ y }, dimX{ d_x }, dimY{ d_y }, sprite{ sprite } {}
SpaceObject::SpaceObject(const SpaceObject* ref) : xPosition{ ref->xPosition }, yPosition{ ref->yPosition }, dimX{ ref->dimX }, dimY{ ref->dimY }, sprite{ ref->sprite }{};

/*
	Checks whether the given target and the object itself collided or not
	@param target: target of question
	@return true if collision false otherwise
*/
bool SpaceObject::checkCollision(SpaceObject* target) {
	if (
		//top right hit
		this->xPosition + this->dimX > target->xPosition &&
		this->xPosition + this->dimX < target->xPosition + target->dimX &&
		this->yPosition > target->yPosition &&
		this->yPosition < target->yPosition + target->dimY
		||
		// bottom right hit
		this->xPosition + this->dimX > target->xPosition &&
		this->xPosition + this->dimX < target->xPosition + target->dimX &&
		this->yPosition + this->dimY > target->yPosition &&
		this->yPosition + this->dimY < target->yPosition + target->dimY
		||
		//bottom left this->xPosition, this->yPosition+this->dimY
		this->xPosition > target->xPosition &&
		this->xPosition < target->xPosition + target->dimX &&
		this->yPosition + this->dimY > target->yPosition &&
		this->yPosition + this->dimY < target->yPosition + target->dimY
		||
		// top left, this->xPosition,this->yPosition
		this->xPosition > target->xPosition &&
		this->xPosition < target->xPosition + target->dimX &&
		this->yPosition > target->yPosition &&
		this->yPosition < target->yPosition + target->dimY
		) {
		return true;
	}
	return false;
}


void SpaceObject::drawObject(olc::PixelGameEngine* p)
{
	p->DrawSprite(this->xPosition, this->yPosition, this->sprite,1);
}


/*
	Checking whether the object is remained in the space coordinates or not

	@param x:Space X dimension
	@param y:Space Y dimension

*/
bool SpaceObject::objectInSpace() {
	if ((this->xPosition + this->dimX > SpaceGameConstants::DIM_X) || (this->yPosition + this->dimY > SpaceGameConstants::DIM_Y)
		|| (this->xPosition + this->dimX <= 0) || (this->yPosition + this->dimY <= 0)) {
		return false;
	}
	return true;
}