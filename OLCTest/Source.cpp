#include "olcSimpleEngine.h"
#include "SpaceGame.h"
#include "SpaceObject.h"
#include "MovingSpaceObject.h"
#include "Box.h"
#include "Asteroid.h"
#include "RegularAsteroid.h"
#include "StrongAsteroid.h"
#include "Bullet.h"
#include "RegularBullet.h"
#include "StrongBullet.h"
#include "EnemyShip.h"
#include "RegularEnemyShip.h"
#include "ShootingEnemyShip.h"
#include "Explosion.h"
#include "Ship.h"
#include <vector>
#include <iostream>





int main()
{
	Box* b = new Box();
	Explosion* exp = new Explosion(b,0);
	RegularAsteroid* ra = new RegularAsteroid();
	StrongAsteroid* sa = new StrongAsteroid();

	Ship* ps = new Ship();
	RegularEnemyShip* res = new RegularEnemyShip();
	ShootingEnemyShip* ses = new ShootingEnemyShip();

	RegularBullet* rb = new RegularBullet(ses);
	StrongBullet* sb = new StrongBullet(ps, 0);

	std::cout << "testing objects" << std::endl;

	SpaceGame game;
	if (game.Construct(400, 400, 1, 1)) {
		game.Start();
	}
	return 0;

}
