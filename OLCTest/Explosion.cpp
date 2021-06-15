#include "Explosion.h"
#include "SpaceObject.h"
#include "olcSimpleEngine.h"

/*
	Constructor
	@param collidedObject: explosion point for collision
	@param explosionTime: time of explosion
	@param lifetime: Lifetime for explosion

*/
Explosion::Explosion(SpaceObject* collidedObject, double explosionTime,ExplosionConstants::ExplosionType type) : SpaceObject(collidedObject), explosionTime{ explosionTime }, lifetime{ ExplosionConstants::LIFETIME }
{
	if (type == ExplosionConstants::ExplosionType::Small) {
		this->sprite = new olc::Sprite(ExplosionConstants::SMALL_SPRITE_LOCATION);
	}
	if (type == ExplosionConstants::ExplosionType::Big) {
		this->sprite = new olc::Sprite(ExplosionConstants::BIG_SPRITE_LOCATION);
	}
};
/*
	Checks whether the explosion has completed it's lifetime or not
	@param currenTime: The moment of comparison
	@return true if lifetime completed false otherwise
*/
bool Explosion::isTimeCompleted(double currentTime) {
	return (currentTime - this->explosionTime > this->lifetime);
}