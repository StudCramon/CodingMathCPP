#include "Arm.h"

void Arm::setPhase(float phase)
{
    angle = centerAngle + sin(phase + phaseOffset) * rotationRange;
}

float Arm::getEndX()
{
    float sumOfAngles = angle;
    Arm* lParent = parent;
    while(lParent)
    {
        sumOfAngles += lParent->angle;
        lParent = lParent->parent;
    }
    return x + cos(sumOfAngles) * lenght;
}

float Arm::getEndY()
{
    float sumOfAngles = angle;
    Arm* lParent = parent;
    while(lParent)
    {
        sumOfAngles += lParent->angle;
        lParent = lParent->parent;
    }
    return y + sin(sumOfAngles) * lenght;
}

void Arm::draw()
{
    Vector2 startPos{x, y};
    Vector2 endPos{getEndX(), getEndY()};
    DrawLineEx(startPos, endPos, 5, BLACK);
}