#ifndef __IKSYSTEM_H__
#define __IKSYSTEM_H__

#include "raylib.h"
#include "Arm.h"
#include <vector>
#include <math.h>

class IKSystem{
public:
    float x = 0;
    float y = 0;
    std::vector<Arm*> arms;
    Arm* lastArm = nullptr;

    IKSystem(float x, float y): x{x}, y{y} {}

    void addArm(float length);
    void draw();
    void drag(float x, float y);
};

#endif // __IKSYSTEM_H__