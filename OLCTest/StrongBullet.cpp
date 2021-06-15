#include "StrongBullet.h"
#include "Bullet.h"
#include "MovingSpaceObject.h"
#include "SpaceObject.h"
#include <vector>




StrongBullet::StrongBullet(MovingSpaceObject* refPoint, Direction direction) : Bullet(refPoint, new olc::Sprite(StrongBulletConstants::SPRITE_LOCATION), StrongBulletConstants::SPEED,direction, BulletConstants::BulletType::Strong) {};



