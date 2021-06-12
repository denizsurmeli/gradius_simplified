#include "SpaceGame.h"
#include "olcSimpleEngine.h"
#include "SpaceObject.h"
#include "MovingSpaceObject.h"
#include "Box.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "EnemyShip.h"
#include "Explosion.h"
#include "Ship.h"
#include <vector>
#include <typeinfo>


SpaceGame::SpaceGame() : gameOver{ false }, gameStarted{ false }, gamePaused{ false }, totalTime{ 0 }, totalScore{ 0 }, boxCount{ 0 }, nuclearCount{ 0 }, regularEnemyCount{ 0 }, shootingEnemyCount{ 0 }, regularAsteroidCount{ 0 }, strongAsteroidCount{ 0 }, ship{ new Ship() }, box{ nullptr }, enemyShips{}, asteroids{}, bullets{}, explosions{}{};

/*
	Draws the game instructions and gameplay
*/
void SpaceGame::displayGameplay() {
	DrawString(150, 100, "SPACESHIP GAME");

	DrawString(125, 125, "PRESS ENTER TO START");

	DrawString(100, 225, "GAMEPLAY");

	DrawString(100, 250, "-USE W-A-S-D TO CONTROL THE SHIP");

	DrawString(100, 275, "-PRESS SPACE TO SHOOT");

	DrawString(100, 300, "-AVOID COLLISIONS");
}



int SpaceGame::calculateScore() {
	return regularAsteroidCount* SpaceGameConstants::POINT_PER_ASTEROID + regularEnemyCount * SpaceGameConstants::POINT_PER_ENEMY + boxCount * SpaceGameConstants::POINT_PER_BOX + nuclearCount * SpaceGameConstants::POINT_PER_NUCLEAR + strongAsteroidCount * SpaceGameConstants::POINT_PER_STRONG_ASTEROID + shootingEnemyCount*SpaceGameConstants::POINT_PER_SHOOTING_ENEMY +int(totalTime);
}




void SpaceGame::displayStats() {
	DrawString(50, 75, "ASTEROIDS HIT: " + std::to_string(regularAsteroidCount));

	DrawString(50, 150, "STRONG ASTEROIDS HIT " + std::to_string(strongAsteroidCount));

	DrawString(50, 100, "ENEMIES HIT: " + std::to_string(regularEnemyCount));

	DrawString(50, 150, "SHOOTING ENEMIES HIT: " + std::to_string(shootingEnemyCount));

	DrawString(50, 125, "BOXES COLLECTED: " + std::to_string(boxCount));

	DrawString(50, 150, "NUCLEAR BLASTS PERFORMED: " + std::to_string(nuclearCount));

	DrawString(50, 175, "YOU HAVE SURVIVED " + std::to_string(totalTime) + " SECONDS");

	DrawString(50, 200, "TOTAL SCORE: " + std::to_string(this->calculateScore()));

}

void SpaceGame::pauseScreen() {
	DrawString(50, 50, "GAME PAUSED");

	DrawString(50, 75, "PRESS ENTER TO CONTINUE");

	this->displayStats();



}

void SpaceGame::endScreen() {
	DrawString(50, 50, "GAME OVER");
	
	this->displayStats();

	DrawString(50, 250, "PRESS E TO EXIT");
}




bool SpaceGame::OnUserCreate() {
	return true;
}

bool SpaceGame::OnUserUpdate(float elapsedTime) {
	return true;
}