#ifndef __ARM_H__
#define __ARM_H__

#include "raylib.h"
#include <math.h>

class Arm{
public:
    Arm* parent = nullptr;

    float x = 0;
    float y = 0;
    float lenght = 100;
    float angle = 0;
    float centerAngle = 0;
    float rotationRange = PI/4;
    float phaseOffset = 0;

    Arm(float lenght, float centerAngle, float rotationRange, float phaseOffset): 
    lenght{lenght}, centerAngle{centerAngle}, rotationRange{rotationRange}, phaseOffset{phaseOffset} {}
    
    Arm() {}


    void setPhase(float phase);
    float getEndX();
    float getEndY();
    void draw();
};

#endif // __ARM_H__