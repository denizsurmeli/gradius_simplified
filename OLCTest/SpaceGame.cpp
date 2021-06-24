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
SpaceGame::SpaceGame() : gameOver{ false }, gameStarted{ false }, gamePaused{ false }, totalTime{ 0 }, totalScore{ 0 }, boxCount{ 0 }, nuclearCount{ 0 }, regularEnemyCount{ 0 }, shootingEnemyCount{ 0 }, regularAsteroidCount{ 0 }, strongAsteroidCount{ 0 }, ship{ nullptr }, box{ nullptr }, regularEnemyShip{ nullptr }, shootingEnemyShip{ nullptr }, regularAsteroid{ nullptr }, strongAsteroid{ nullptr }, shipBullet{ nullptr }, lastRegularEnemyTime{ 0 }, lastRegularAsteroidTime{ 0 }, lastShootingEnemyTime{ 0 }, lastStrongAsteroidTime{ 0 }, lastBoxCount{ 0 }, enemyBullets{}, explosions{}, objects{}{

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

/*
	Listens key presses from the user, takes the possible action
*/
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
		if (this->shipBullet == nullptr) {
			this->shipBullet = this->ship->fireBullet(this->totalTime);
		}
	}
	//Capturing the nuclear power with mouse click
	if (GetMouse(0).bPressed) {
		//if box does exist
		if (this->box != nullptr) {
			//give the coordinates to box, check whether the click is eligible for nuclear power
			if (this->box->checkMouseClick(GetMouseX(), GetMouseY())) {
				//@TODO:
				if (!this->ship->shipCanUseNuclear()) {
					this->ship->toggleNuclear();
				}

				delete this->box;
				this->box = nullptr;
			}
		}
	}
	//use nuclear power
	if (GetKey(olc::SHIFT).bPressed) {
		//@TODO:
		if (this->ship->shipCanUseNuclear()) {
			this->generateNuclearEffect();
			this->ship->toggleNuclear();
		}

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

SpaceGameConstants::CollisionTypes SpaceGame::checkCollisions() {
	std::vector<SpaceObject*> candidates{ this->regularAsteroid,this->regularEnemyShip,this->strongAsteroid,this->shootingEnemyShip };
	//ship to something
	if (this->ship != nullptr) {
		//ship to regular asteroid
		if (this->regularAsteroid != nullptr) {
			if (this->ship->checkCollision(this->regularAsteroid)) {
				this->gameOver = true;
			}
		}
		if (this->regularEnemyShip != nullptr) {
			if (this->ship->checkCollision(this->regularEnemyShip)) {
				this->gameOver = true;
			}
		}
		if (this->shootingEnemyShip != nullptr) {
			if (this->ship->checkCollision(this->shootingEnemyShip)) {
				this->gameOver = true;
			}
		}
		if (this->strongAsteroid != nullptr) {
			if (this->ship->checkCollision(this->strongAsteroid)) {
				this->gameOver = true;
				
			}
		}
		if (this->box != nullptr) {
			if (this->ship->checkCollision(this->box)) {
				this->boxCount++;
				
				if (!this->ship->shipCanUseNuclear()) {
					this->ship->toggleNuclear();
				}

				delete this->box;
				this->box = nullptr;
			}
		}
	}



	//ship bullet to something
	if (this->shipBullet != nullptr) {
		//ship bullet to regular enemy
		if (this->regularEnemyShip != nullptr) {
			if (this->shipBullet->checkCollision(regularEnemyShip)) {
				//todo:add explosion
				this->generateExplosion(this->regularEnemyShip, this->totalTime,ExplosionConstants::ExplosionType::Big);

				this->regularEnemyCount++;

				delete this->regularEnemyShip;
				this->regularEnemyShip = nullptr;

				if (this->shipBullet->getType() == BulletConstants::BulletType::Regular) {
					if (this->shipBullet != nullptr) {
						delete this->shipBullet;
						this->shipBullet = nullptr;
					}
				}
				else if (this->shipBullet->getType() == BulletConstants::BulletType::Strong) {
					std::vector<SpaceObject*> nearbyObjects = this->shipBullet->getNearbyEnemies(candidates);
					this->generateShrapnelEffect(nearbyObjects);

					if (this->shipBullet != nullptr) {
						delete this->shipBullet;
						this->shipBullet = nullptr;
					}
				}


				this->ship->toggleFire();

				return SpaceGameConstants::CollisionTypes::BulletToEnemyShip;
			}
		}
		//ship bullet to regular asteorid
		if (this->regularAsteroid != nullptr) {
			if (this->shipBullet->checkCollision(regularAsteroid)) {
				//todo:add explosion
				this->generateExplosion(this->regularAsteroid, this->totalTime, ExplosionConstants::ExplosionType::Big);

				this->regularAsteroidCount++;

				if (this->shipBullet->getType() == BulletConstants::BulletType::Regular) {
					if (this->shipBullet != nullptr) {
						delete this->shipBullet;
						this->shipBullet = nullptr;
					}
				}
				else if (this->shipBullet->getType() == BulletConstants::BulletType::Strong) {
					std::vector<SpaceObject*> nearbyObjects = this->shipBullet->getNearbyEnemies(candidates);
					this->generateShrapnelEffect(nearbyObjects);
	
					if (this->shipBullet != nullptr) {
						delete this->shipBullet;
						this->shipBullet = nullptr;
					}
				}
				
				delete this->regularAsteroid;
				this->regularAsteroid = nullptr;

				this->ship->toggleFire();

				return SpaceGameConstants::CollisionTypes::BulletToAsteroid;

			}
		}
		//ship bullet to strong asteroid 
		if (this->strongAsteroid != nullptr) {
			if (this->shipBullet->checkCollision(strongAsteroid)) {
				//todo:add explosion
				

				if (this->shipBullet->getType() == BulletConstants::BulletType::Regular) {
					this->strongAsteroid->reduceHealth();
					if (this->shipBullet != nullptr) {
						delete this->shipBullet;
						this->shipBullet = nullptr;
					}
					if (this->strongAsteroid->isDead()) {
						this->generateExplosion(this->strongAsteroid, this->totalTime, ExplosionConstants::ExplosionType::Big);
						this->strongAsteroidCount++;

						this->ship->captureStrongBullet(this->totalTime);

						delete this->strongAsteroid;
						this->strongAsteroid = nullptr;
					}
				}
				else if (this->shipBullet->getType() == BulletConstants::BulletType::Strong) {
					std::vector<SpaceObject*> nearbyObjects = this->shipBullet->getNearbyEnemies(candidates);
					this->generateShrapnelEffect(nearbyObjects);
					this->generateExplosion(this->strongAsteroid, this->totalTime, ExplosionConstants::ExplosionType::Big);


					this->strongAsteroidCount++;

					this->ship->captureStrongBullet(this->totalTime);

					if (this->shipBullet != nullptr) {
						delete this->shipBullet;
						this->shipBullet = nullptr;
					}

					delete this->strongAsteroid;
					this->strongAsteroid = nullptr;
				}
				this->ship->toggleFire();

				return SpaceGameConstants::CollisionTypes::BulletToStrongAsteroid;
			}

		}

		//ship bullet to shooting enemy
		if (this->shootingEnemyShip != nullptr) {
			if (this->shipBullet->checkCollision(shootingEnemyShip)) {
				//todo:add explosion
				if (this->shipBullet->getType() == BulletConstants::BulletType::Regular) {
					this->shootingEnemyShip->reduceHealth();

					if (this->shootingEnemyShip->isDead()) {

						this->generateExplosion(this->shootingEnemyShip, this->totalTime, ExplosionConstants::ExplosionType::Big);
						this->shootingEnemyCount++;

						this->ship->captureStrongBullet(this->totalTime);

						delete this->shootingEnemyShip;
						this->shootingEnemyShip = nullptr;

						for (auto& ob : this->enemyBullets) {
							if (ob != nullptr) {
								delete ob;
								ob = nullptr;
							}
						}
						this->enemyBullets = std::vector<RegularBullet*>{};
					}

					if (this->shipBullet != nullptr) {
						delete this->shipBullet;
						this->shipBullet = nullptr;
					}
				}
				else if (this->shipBullet->getType() == BulletConstants::BulletType::Strong) {
					std::vector<SpaceObject*> nearbyObjects = this->shipBullet->getNearbyEnemies(candidates);
					
					this->generateShrapnelEffect(nearbyObjects);
					this->generateExplosion(this->shootingEnemyShip, this->totalTime, ExplosionConstants::ExplosionType::Big);
					
			
					if (this->shipBullet != nullptr) {
						delete this->shipBullet;
						this->shipBullet = nullptr;
					}

					this->shootingEnemyCount++;
					this->ship->captureStrongBullet(this->totalTime);

					delete this->shootingEnemyShip;
					this->shootingEnemyShip = nullptr;
				}

				this->ship->toggleFire();

				return SpaceGameConstants::CollisionTypes::BulletToShootingEnemy;
			}
		}

	}

	//shooting enemy bullet to ship
	if (this->enemyBullets.size() > 0) {
		for (auto& ob : this->enemyBullets) {
			if (ob != nullptr) {
				if (ob->objectInSpace()) {
					if (ob->checkCollision(this->ship)) {
						delete ob;
						ob = nullptr;
						this->ship->reduceHealth();
					}
				}
			}
		}
	}


	return SpaceGameConstants::CollisionTypes::NAC;
}

/*
	Generates auto targets(Objects like Asteroids and EnemyShips are
	generated automatically with random coordinates.) and handling of them
	@param fElapsedTime: time taken for displacement
*/
void SpaceGame::generateTargets(float elapsedTime) {
	//regular enemy ship generation
	if (this->regularEnemyShip == nullptr && (this->totalTime - this->lastRegularEnemyTime) > SpaceGameConstants::REGEN_REG_ENEMY) {
		this->lastRegularEnemyTime = this->totalTime;
		this->regularEnemyShip = new RegularEnemyShip();
	}


	//regular asteroid generation
	if (this->regularAsteroid == nullptr && (this->totalTime - this->lastRegularAsteroidTime) > SpaceGameConstants::REGEN_REG_ASTEROID) {
		this->lastRegularAsteroidTime = this->totalTime;
		this->regularAsteroid = new RegularAsteroid();
	}


	//strong asteroid generation
	if (this->strongAsteroid == nullptr && (this->totalTime - this->lastStrongAsteroidTime) > SpaceGameConstants::REGEN_ST_ASTEROID) {
		this->lastStrongAsteroidTime = this->totalTime;
		this->strongAsteroid = new StrongAsteroid();
	}


	//shooting enemy generation
	if (this->shootingEnemyShip == nullptr && (this->totalTime - this->lastShootingEnemyTime) > SpaceGameConstants::REGEN_STG_ENEMY) {
		this->lastShootingEnemyTime = this->totalTime;
		this->shootingEnemyShip = new ShootingEnemyShip();
	}


	//shooting enemy bullet generation
	//@todo:
	if (this->shootingEnemyShip != nullptr && this->shootingEnemyShip->canFire(this->totalTime)) {
		this->enemyBullets.push_back(this->shootingEnemyShip->fireBullet(this->totalTime));
	}


	//box generation
	if (this->box == nullptr && (this->regularEnemyCount + 2 * this->shootingEnemyCount) - this->lastBoxCount >= SpaceGameConstants::REGEN_BOX && !(this->ship->shipCanUseNuclear())) {
		this->lastBoxCount = this->regularEnemyCount + 2* this->shootingEnemyCount;
		this->box = new Box();
	}

}

void SpaceGame::generateExplosion(SpaceObject* target, float currentTime, ExplosionConstants::ExplosionType type)
{
	this->explosions.push_back(new Explosion(target, this->totalTime,type));
}

void SpaceGame::generateNuclearEffect()
{
	if (this->regularAsteroid != nullptr) {
		this->generateExplosion(this->regularAsteroid, this->totalTime,  ExplosionConstants::ExplosionType::Big);

		delete this->regularAsteroid;
		this->regularAsteroid = nullptr;
	}
	if (this->regularEnemyShip != nullptr) {
		this->generateExplosion(this->regularEnemyShip, this->totalTime,  ExplosionConstants::ExplosionType::Big);
		
		delete this->regularEnemyShip;
		this->regularEnemyShip = nullptr;
	}
	if(this->strongAsteroid != nullptr){
		this->generateExplosion(this->strongAsteroid, this->totalTime, ExplosionConstants::ExplosionType::Big);

		delete this->strongAsteroid;
		this->strongAsteroid = nullptr;
	}
	if (this->shootingEnemyShip != nullptr) {
		this->generateExplosion(this->shootingEnemyShip, this->totalTime,  ExplosionConstants::ExplosionType::Big);
	
		delete this->shootingEnemyShip;
		this->shootingEnemyShip = nullptr;
	}
}

void SpaceGame::generateShrapnelEffect(std::vector<SpaceObject*> effected) {
	for (auto& ob : effected) {
		if (ob != nullptr) {
			if (ob == this->regularEnemyShip) {
				this->generateExplosion(this->regularEnemyShip, this->totalTime, ExplosionConstants::ExplosionType::Big);
				this->regularEnemyCount++;

				delete this->regularEnemyShip;
				this->regularEnemyShip = nullptr;
			}
			if (ob == this->regularAsteroid) {
				this->generateExplosion(this->regularAsteroid, this->totalTime, ExplosionConstants::ExplosionType::Big);
				this->regularAsteroidCount++;

				delete this->regularAsteroid;
				this->regularAsteroid = nullptr;
			}
			if (ob == this->strongAsteroid) {
				this->strongAsteroid->reduceHealth();
				if (this->strongAsteroid->isDead()) {
					this->generateExplosion(this->strongAsteroid,this->totalTime, ExplosionConstants::ExplosionType::Big);

					this->strongAsteroidCount++;
					this->ship->captureStrongBullet(this->totalTime);

					delete this->strongAsteroid;
					this->strongAsteroid = nullptr;
				}
				else if(this->strongAsteroid != nullptr){
					this->generateExplosion(this->strongAsteroid, this->totalTime, ExplosionConstants::ExplosionType::Small);
				}
			}
			if (ob == this->shootingEnemyShip) {
				this->shootingEnemyShip->reduceHealth();
				if (this->shootingEnemyShip->isDead()) {
					this->generateExplosion(this->shootingEnemyShip, this->totalTime, ExplosionConstants::ExplosionType::Big);

					this->shootingEnemyCount++;
					this->ship->captureStrongBullet(this->totalTime);

					delete this->shootingEnemyShip;
					this->shootingEnemyShip = nullptr;
				}
				else if(this->shootingEnemyShip != nullptr){
					this->generateExplosion(this->shootingEnemyShip, this->totalTime, ExplosionConstants::ExplosionType::Small);
				}
			}
		}

		effected.clear();
	}

}

void SpaceGame::generateObjectList() {
	this->objects = std::vector<SpaceObject*>{ ship, box, regularEnemyShip, shootingEnemyShip, regularAsteroid, strongAsteroid, shipBullet };
	for (auto& ob : this->explosions) {
		if (ob != nullptr) {
			this->objects.push_back(ob);
		}
	}
	for (auto& ob : this->enemyBullets) {
		if (ob != nullptr) {
			this->objects.push_back(ob);
		}
	}
}

void SpaceGame::updateShips(float elapsedTime) {
	if (this->regularEnemyShip != nullptr) {
		if (!(this->regularEnemyShip->objectInSpace())) {
			delete this->regularEnemyShip;
			this->regularEnemyShip = nullptr;
		}else{
			this->regularEnemyShip->move(elapsedTime);

		}

	}

	if (this->shootingEnemyShip != nullptr) {
		if (!(this->shootingEnemyShip->objectInSpace())) {
			delete this->shootingEnemyShip;
			this->shootingEnemyShip = nullptr;

			for (auto& ob : this->enemyBullets) {
				if (ob != nullptr) {
					delete ob;
					ob = nullptr;
				}
			}
			this->enemyBullets = std::vector<RegularBullet*>{};
		}
		else {
			this->shootingEnemyShip->move(this->ship, elapsedTime);
		}
	}
	if (this->ship->isDead()) {
		this->gameOver = true;
	}

}

void SpaceGame::updateAsteroids(float elapsedTime) {
	if (this->regularAsteroid != nullptr) {
		if (!(this->regularAsteroid->objectInSpace())) {
			delete this->regularAsteroid;
			this->regularAsteroid = nullptr;
		}
		else {
			this->regularAsteroid->move(elapsedTime);
		}
	}

	if (this->strongAsteroid != nullptr) {
		if (!(this->strongAsteroid->objectInSpace())) {
			this->gameOver = true;

			delete this->strongAsteroid;
			this->strongAsteroid = nullptr;
		}
		else {
			this->strongAsteroid->move(elapsedTime);
		}
	}
}

void SpaceGame::updateBullets(float elapsedTime) {
	if (this->shipBullet != nullptr) {
		this->shipBullet->move(elapsedTime);
		if (!(this->shipBullet->objectInSpace())) {
			delete this->shipBullet;
			this->shipBullet = nullptr;

			this->ship->toggleFire();
		}
		else {
			this->shipBullet->move(elapsedTime);
		}
	}
	//todo:enemy bullets
	for (auto& ob : enemyBullets) {
		if (ob != nullptr) {
			ob->move(elapsedTime);
			if (!ob->objectInSpace()) {
				if (this->shootingEnemyShip != nullptr) {
					this->shootingEnemyShip->reduceCount();
				}
				delete ob;
				ob = nullptr;
			}
		}
	}
}

void SpaceGame::updateExplosions() {
	std::vector<Explosion*> temp{};

	for (auto& ob : this->explosions) {
		if (ob->isTimeCompleted(this->totalTime)) {
			delete ob;
			ob = nullptr;
		}
		else {
			temp.push_back(ob);
		}
	}

	this->explosions.clear();
	this->explosions = temp;

}

void SpaceGame::updateAll(float elapsedTime) {
	
	this->updateAsteroids(elapsedTime);
	
	this->updateShips(elapsedTime);

	this->updateBullets(elapsedTime);

	this->updateExplosions();

	this->checkCollisions();
}

void SpaceGame::drawObjects() {
	for (auto ob : this->objects) {
		if (ob != nullptr) {
			ob->drawObject(this);
		}
	}
}









bool SpaceGame::OnUserCreate() {
	this->ship = new Ship();
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

				this->generateTargets(fElapsedTime);

				this->updateAll(fElapsedTime);

				this->generateObjectList();
				
				this->drawObjects();

				this->totalTime += fElapsedTime;

				std::this_thread::sleep_for(std::chrono::milliseconds(8));

				this->objects.clear();


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
