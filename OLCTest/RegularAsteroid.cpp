#include "RegularAsteroid.h"
#include "Asteroid.h"

RegularAsteroid::RegularAsteroid() :Asteroid(RegularAsteroidConstants::DIM_X, RegularAsteroidConstants::DIM_X, new olc::Sprite(RegularAsteroidConstants::SPRITE_LOCATION), RegularAsteroidConstants::SPEED) {};