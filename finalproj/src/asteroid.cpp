#include "asteroid.hpp"
#include <cstdlib>

Asteroid::Asteroid()
{
	int radius = 300;
	float r = rand() % radius;
	float phi = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 3.14159));
	float theta = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 3.14159 / 2));

	x = r*cos(theta)*sin(phi)+30;
	y = r*sin(theta)*sin(phi)+30;
	z = r*cos(phi)+30;

	vx = 2 * ((rand() % 10) - 5);
	vy = 2 * ((rand() % 10) - 5);
	vz = 2 * ((rand() % 10) - 5);

	rx = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 3.14159 / 2));
	ry = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 3.14159 / 2));
	rz = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 3.14159 / 2));
}

void Asteroid::tick()
{
	x += vx/100;
	y += vy/100;
	z += vz/100;

	rx += 0.01;
	ry += 0.01;
	rz += 0.01;
}
