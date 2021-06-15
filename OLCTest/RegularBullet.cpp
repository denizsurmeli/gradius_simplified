#include "RegularBullet.h"
#include "Bullet.h"
#include "SpaceObject.h"
#include "MovingSpaceObject.h"

RegularBullet::RegularBullet(MovingSpaceObject* refPoint,Direction direction) : Bullet(refPoint, new olc::Sprite(RegularBulletConstants::SPRITE_LOCATION), RegularBulletConstants::SPEED,direction, BulletConstants::BulletType::Regular) {};

