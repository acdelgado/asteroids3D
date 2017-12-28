#include "bullet.hpp"

Bullet::Bullet(): live(0) {}

void Bullet::tick()
{
		x += vx;
		y += vy;
		z += vz;
		live++;
}
