#pragma once
#include "SpaceObject.h"
//Explosion Constants
namespace ExplosionConstants {
    constexpr auto LIFETIME = 0.5;
    constexpr auto BIG_SPRITE_LOCATION = "Sprites/exp2.png";
    constexpr auto SMALL_SPRITE_LOCATION = "Sprites/explosion.png";
    enum class ExplosionType {
        Small = 1,
        Big = 2
    };
}
/*
    Explosion class
*/
class Explosion :
    public SpaceObject
{
private:
    double explosionTime; //snapshot of explosion time
    double lifetime;      //lifetime
public:
    Explosion(SpaceObject* collidedObject, double explosionTime,ExplosionConstants::ExplosionType type); //constructor
    bool isTimeCompleted(double currentTime); //Checks whether the lifetime is completed or not

};