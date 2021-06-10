#pragma once
#include "SpaceObject.h"
//Explosion Constants
namespace ExplosionConstants {
    constexpr auto LIFETIME = 0.5;

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
    Explosion(SpaceObject* collidedObject, double explosionTime, double lifetime); //constructor
    bool isTimeCompleted(double currentTime); //Checks whether the lifetime is completed or not

};