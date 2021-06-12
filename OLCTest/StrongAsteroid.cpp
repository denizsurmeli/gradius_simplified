#include "StrongAsteroid.h"
#include "Asteroid.h";

StrongAsteroid::StrongAsteroid() :Asteroid(StrongAsteroidConstants::DIM_X, StrongAsteroidConstants::DIM_X, new olc::Sprite(StrongAsteroidConstants::SPRITE_LOCATION), StrongAsteroidConstants::SPEED), hitCount{ 0 }{};