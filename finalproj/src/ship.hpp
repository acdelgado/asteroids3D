#pragma once

class Ship
{
private:
    float angel_;
public:
	float x;
	float y;
	float z;
    Ship();
	void tick(float cx, float cy, float cz);
};
