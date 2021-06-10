#include "EnemyShip.h"
#include "MovingSpaceObject.h"
#include "olcSimpleEngine.h"

EnemyShip::EnemyShip(int x, int y, double dimX, double dimY, olc::Sprite* sprite, double speed) :MovingSpaceObject(x, y, dimX, dimY, sprite, speed) {};