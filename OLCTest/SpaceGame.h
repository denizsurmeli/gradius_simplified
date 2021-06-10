#pragma once
#include "olcSimpleEngine.h"

namespace SpaceGameConstants {
	//point values per object for statistics
	constexpr auto POINT_PER_BOX = 3;
	constexpr auto POINT_PER_ASTEROID = 3;
	constexpr auto POINT_PER_ENEMY = 5;
	constexpr auto POINT_PER_NUCLEAR = 4;

	//space dimensions
	constexpr auto DIM_X = 400;
	constexpr auto DIM_Y = 400;

	//Sampling and scaling constants
	constexpr auto SAMPLE = 1;
	constexpr auto SCALE = 1;

	//Types of collision, debugging purposes
	enum class CollisionTypes {
		BulletToAsteroid = 1,
		BulletToEnemyShip = 2,
		ShipToAsteroid = 3,
		ShipToEnemyShip = 4,
		ShipToBox = 5,
		NAC = 0, //Not a Collision

	};
}

class SpaceGame:public olc::PixelGameEngine
{
};

