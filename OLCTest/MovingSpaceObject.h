#pragma once
#include "SpaceObject.h"


//Direction types for better readability
enum class Direction {
	PX = 1, //Plus x
	PY = 2, //Plus y
	NX = 3, //Minus x
	NY = 4, //Minus y

};



class MovingSpaceObject :
    public SpaceObject
{
protected:
	double speed;

public:
	MovingSpaceObject(int x, int y, double d_x, double d_y, olc::Sprite* spriteRef, double speed);
	virtual void move(Direction direction, float elapsedTime);
	explicit virtual void move(float elapsedTime) = 0;
	
};

