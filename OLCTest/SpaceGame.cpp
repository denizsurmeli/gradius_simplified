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
#include <iostream>
#include <chrono>
#include <thread>
SpaceGame::SpaceGame() : gameOver{ false }, gameStarted{ false }, gamePaused{ false }, totalTime{ 0 }, totalScore{ 0 }, boxCount{ 0 }, nuclearCount{ 0 }, regularEnemyCount{ 0 }, shootingEnemyCount{ 0 }, regularAsteroidCount{ 0 }, strongAsteroidCount{ 0 }, ship{ nullptr }, box{ nullptr }, regularEnemyShip{ nullptr }, shootingEnemyShip{ nullptr }, regularAsteroid{ nullptr }, strongAsteroid{ nullptr }, shipBullet{ nullptr }, enemyBullets{}, explosions{}, objects{}{

};

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



void SpaceGame::drawObjects() {
	for (auto ob : this->objects) {
		if (ob != nullptr) {
			ob->drawObject(this);
		}
	}
}
void SpaceGame::generateObjectList() {
	this->objects = std::vector<SpaceObject*>{ ship, box, regularEnemyShip, shootingEnemyShip, regularAsteroid, strongAsteroid, shipBullet };
	for (auto ob : enemyBullets) {
		this->objects.push_back(ob);
	}
	for (auto ob : explosions) {
		this->objects.push_back(ob);
	}
}

void SpaceGame::listenKeyPress(double elapsedTime) {
	//User ship movement(up,down,right,left)
	if (GetKey(olc::W).bHeld) {
		this->ship->move(Direction::NY, elapsedTime);
	}if (GetKey(olc::A).bHeld) {
		this->ship->move(Direction::NX, elapsedTime);
	}if (GetKey(olc::S).bHeld) {
		this->ship->move(Direction::PY, elapsedTime);
	}if (GetKey(olc::D).bHeld) {
		this->ship->move(Direction::PX, elapsedTime);
	}
	//Firing a bullet
	if (GetKey(olc::SPACE).bPressed) {
		//Checking the constraints for shooting a bullet
		//@TODO:
	}
	//Capturing the nuclear power with mouse click
	if (GetMouse(0).bPressed) {
		//if box does exist
		if (this->box != nullptr) {
			//give the coordinates to box, check whether the click is eligible for nuclear power
			if (this->box->checkMouseClick(GetMouseX(), GetMouseY())) {
				//@TODO:
				delete this->box;
				this->box = nullptr;
			}
		}
	}
	//use nuclear power
	if (GetKey(olc::SHIFT).bPressed) {
		//@TODO:
		
	}
	//if game paused:continue
	//if the game hasn't started: start the game
	if (GetKey(olc::ENTER).bPressed) {
		if (this->gameStarted == false) {
			this->gameStarted = true;
		}
		else {
			this->gamePaused = false;
		}
	}
	//pause the game
	if (GetKey(olc::P).bPressed) {
		this->gamePaused = true;
	}
}


bool SpaceGame::OnUserCreate() {
	this->ship = new Ship();
	this->box = new Box();
	return true;
}

bool SpaceGame::OnUserUpdate(float fElapsedTime) {
	Clear(olc::DARK_GREEN);
	SetPixelMode(olc::Pixel::ALPHA);

	if (this->gameStarted) {
		//If game is ended, show the end screen.
		if (this->gameOver) {
			//@TODO: write a cleaner for memory leaks
			this->endScreen();
			if (GetKey(olc::E).bPressed)
				return false;
			else
				return true;
		}
		else {

			//Listens key strokes
			this->listenKeyPress(fElapsedTime);
			if (this->gamePaused) {
				this->pauseScreen();
				return true;
			}
			else/*gameplay runs here*/ {
				this->generateObjectList();
				
				this->drawObjects();

				this->totalTime += fElapsedTime;

				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				return true;
			}
		}
	}
	else {
		//the beginning screen
		this->displayGameplay();
		this->listenKeyPress(fElapsedTime);
	}

	return true;
}