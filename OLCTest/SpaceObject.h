#pragma once
#include "olcSimpleEngine.h"





namespace SpaceObjectConstants {
	constexpr auto SPACE_X = 400;
	constexpr auto SPACE_Y = 400;
}

class SpaceObject
{
protected:
	int xPosition;
	int yPosition;
	double dimX;
	double dimY;
	olc::Sprite* sprite;

public:
	SpaceObject();
	SpaceObject(int x, int y, double d_x, double d_y, olc::Sprite* sprite);
	explicit SpaceObject(const SpaceObject* ref);

	virtual bool objectInSpace();
	virtual bool checkCollision(SpaceObject* target);

	//only used in Bullet and derived classes.
	//@todo:find a solution for this getter case.
	int getX() { return this->xPosition; };
	int getY() { return this->yPosition; };

	//void drawObject(SpaceGame* p,int scale);
	
};

