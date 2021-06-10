#include "Explosion.h"
#include "SpaceObject.h"
#include "olcSimpleEngine.h"

/*
	Constructor
	@param collidedObject: explosion point for collision
	@param explosionTime: time of explosion
	@param lifetime: Lifetime for explosion

*/
Explosion::Explosion(SpaceObject* collidedObject, double explosionTime, double lifetime = ExplosionConstants::LIFETIME) : SpaceObject(collidedObject), explosionTime{ explosionTime }, lifetime{ lifetime }
{
	this->sprite = new olc::Sprite("Sprites/explosion.png");
};
/*
	Checks whether the explosion has completed it's lifetime or not
	@param currenTime: The moment of comparison
	@return true if lifetime completed false otherwise
*/
bool Explosion::isTimeCompleted(double currentTime) {
	return (currentTime - this->explosionTime > this->lifetime);
}