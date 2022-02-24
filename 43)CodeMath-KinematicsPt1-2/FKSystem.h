#ifndef __FKSYSTEM_H__
#define __FKSYSTEM_H__

#include "raylib.h"
#include "Arm.h"
#include <vector>

class FKSystem{
public:
    std::vector<Arm*> arms;
    Arm* lastArm = nullptr;
    float x = 0;
    float y = 0;
    float phase = 0;
    float speed = 0.05;

    FKSystem(float x, float y): x{x}, y{y} {}

    void addArm(float length, float centerAngle, float rotationRange, float phaseOffset);
    void update();
    void draw();
    void rotate(int index, float angle);
};

#endif // __FKSYSTEM_H__