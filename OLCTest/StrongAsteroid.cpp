#include "StrongAsteroid.h"
#include "Asteroid.h";

StrongAsteroid::StrongAsteroid() :Asteroid(StrongAsteroidConstants::DIM_X, StrongAsteroidConstants::DIM_X, new olc::Sprite(StrongAsteroidConstants::SPRITE_LOCATION), StrongAsteroidConstants::SPEED), hitCount{ 0 }{};



void StrongAsteroid::reduceHealth() {
	this->speed = this->speed / 128000;
	this->hitCount++;
}

bool StrongAsteroid::isDead() {
	return this->hitCount == StrongAsteroidConstants::LIFE;
}


