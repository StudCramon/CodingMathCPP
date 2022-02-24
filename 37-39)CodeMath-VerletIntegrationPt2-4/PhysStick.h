#ifndef __PHYSSTICK_H__
#define __PHYSSTICK_H__

#include "raylib.h"
#include "PhysicsEntity.h"
#include <math.h>
#include <iostream>

class Stick{
public:
    PhysEnt* p1;
    PhysEnt* p2;
    float lenght;
    bool isHidden = false;
    Color stickColor = RED;
    float thick = 5;

    Stick(PhysEnt* p1, PhysEnt* p2);

    void update(int percision = 1);
    void draw();
};

#endif // __PHYSSTICK_H__