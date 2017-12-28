#pragma once

struct Bullet
{
    Bullet();
    void tick();
    float vx;
    float vy;
	float vz;
    float x;
    float y;
	float z;
    int live;
};
