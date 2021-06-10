#pragma once
#include "SpaceObject.h"
//Box constants
namespace BoxConstants {
	constexpr auto DIM_X = 30;
	constexpr auto DIM_Y = 20;
}

/*
	Box class
*/
class Box : public SpaceObject
{
public:
	Box(); //constructor
	bool checkMouseClick(int x, int y); //checks whether the mouse coordinates intersected with box's position and area or not

};