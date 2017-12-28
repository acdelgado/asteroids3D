#include "ship.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

Ship::Ship(): angel_(3.14159 / 2)
{
	x = 0;
	y = -0.5;
	z = -2;
}

void Ship::tick(float cx, float cy, float cz)
{
	x = cx - 2;
	y = cy -0.5;
	z = cz;
}

