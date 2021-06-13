#pragma once
#include "olcSimpleEngine.h"
#include "SpaceObject.h"
#include "MovingSpaceObject.h"
#include "Box.h"
#include "Asteroid.h"
#include "RegularAsteroid.h"
#include "StrongAsteroid.h"
#include "Bullet.h"
#include "RegularBullet.h"
#include "StrongBullet.h"
#include "EnemyShip.h"
#include "RegularEnemyShip.h"
#include "ShootingEnemyShip.h"
#include "Explosion.h"
#include "Ship.h"
#include <vector>

namespace SpaceGameConstants {
	//point values per object for statistics
	constexpr auto POINT_PER_BOX = 3;
	constexpr auto POINT_PER_ASTEROID = 3;
	constexpr auto POINT_PER_ENEMY = 5;
	constexpr auto POINT_PER_NUCLEAR = 4;
	constexpr auto POINT_PER_STRONG_ASTEROID = 9;
	constexpr auto POINT_PER_SHOOTING_ENEMY = 15;

	//regen times for objects
	constexpr auto REGEN_REG_ENEMY = 5;
	constexpr auto REGEN_STG_ENEMY = 10;
	constexpr auto REGEN_REG_ASTEROID = 5;
	constexpr auto REGEN_ST_ASTEROID = 12;
	constexpr auto REGEN_BOX = 5;

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
		BulletToShootingEnemy = 3,
		BulletToStrongAsteroid = 4,
		StrongBulletToAnyTarget = 5,
		ShipToAsteroid = 6,
		ShipToStrongAsteroid = 7,
		ShipToShootingEnemy = 8,
		ShipToEnemyShip = 9,
		ShipToBox = 10,
		NAC = 0, //Not a Collision

	};
}

class SpaceGame:public olc::PixelGameEngine
{
public:
	//Constructor

	SpaceGame();

	//Overrides

	bool OnUserUpdate(float fElapsedTime);
	bool OnUserCreate();

	//Screens

	void displayStats();
	void displayGameplay();
	void pauseScreen();
	void endScreen();
	int calculateScore();

	//Listeners and oracles
	void listenKeyPress(double elapsedTime);
	SpaceGameConstants::CollisionTypes checkCollisions();


	//generators
	void generateTargets(float elapsedTime);
	void generateExplosion(SpaceObject* target, float currentTime);
	void generateNuclearEffect();
	void generateObjectList();

	//Renderers,updaters and drawers
	void drawObjects();

	void updateExplosions();
	void updateBullets(float elapsedTime);
	void updateShips();
	void updateAsteroids();
	void updateAll(float elapsedTime);

	void render();



private:

	//State of the game
	bool gameOver;
	bool gameStarted;
	bool gamePaused;
	//Statistics
	float totalTime;
	float totalScore;

	//Counters
	int boxCount;
	int nuclearCount;
	int regularEnemyCount;
	int shootingEnemyCount;
	int regularAsteroidCount;
	int strongAsteroidCount;
	
	//time oracles
	double lastRegularEnemyTime;
	double lastShootingEnemyTime;
	double lastRegularAsteroidTime;
	double lastStrongAsteroidTime;

	//count oracles
	int lastBoxCount;

	//Objects
	Ship* ship;
	Box* box;
	RegularEnemyShip* regularEnemyShip;
	ShootingEnemyShip* shootingEnemyShip;
	RegularAsteroid* regularAsteroid;
	StrongAsteroid* strongAsteroid;
	Bullet* shipBullet;
	std::vector<RegularBullet*> enemyBullets;
	std::vector<Explosion*> explosions;

	std::vector<SpaceObject*> objects;

};

