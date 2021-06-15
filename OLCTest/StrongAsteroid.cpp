#include "StrongAsteroid.h"
#include "Asteroid.h";

StrongAsteroid::StrongAsteroid() :Asteroid(StrongAsteroidConstants::DIM_X, StrongAsteroidConstants::DIM_X, new olc::Sprite(StrongAsteroidConstants::SPRITE_LOCATION), StrongAsteroidConstants::SPEED), hitCount{ 0 }{}
void StrongAsteroid::move(float elapsedTime)
{
	if (this->xPosition <= 0) {
		this->xPosition -= 1;
	}
	this->xPosition -= this->speed * elapsedTime;
}
;



void StrongAsteroid::reduceHealth() {
	this->speed = this->speed;
	this->hitCount++;
}

bool StrongAsteroid::isDead() {
	return this->hitCount == StrongAsteroidConstants::LIFE;
}


