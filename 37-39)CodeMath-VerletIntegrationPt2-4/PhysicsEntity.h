#ifndef __PHYSICSENTITY_H__
#define __PHYSICSENTITY_H__

#include "raylib.h"

class PhysEnt
{
public:
    float x;
    float y;
    float oldx;
    float oldy;
    float bounce = 0.9;
    float gravity = 0.5;
    float friction = 0.9999;

    bool isStatic = false;

    PhysEnt(float x = 0, float y = 0, float oldx = 0, float oldy = 0): x{x}, y{y}, oldx{oldx}, oldy{oldy} {}

    void update();
    void draw();
    void checkConstraints();
};

#endif // __PHYSICSENTITY_H__