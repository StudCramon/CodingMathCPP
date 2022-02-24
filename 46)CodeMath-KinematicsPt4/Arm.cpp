#include "Arm.h"

float Arm::getEndX()
{
    return x + cos(angle) * length;
}

float Arm::getEndY()
{
    return y + sin(angle) * length;
}

void Arm::draw()
{
    Vector2 startPos{x, y};
    Vector2 endPos{getEndX(), getEndY()};
    DrawLineEx(startPos, endPos, 5, BLACK);
}

void Arm::pointAt(float x, float y)
{
    float dx = x - this->x;
    float dy = y - this->y;
    angle = atan2(dy, dx);
}

void Arm::drag(float x, float y)
{
    pointAt(x, y);
    this->x = x - cos(angle) * length;
    this->y = y - sin(angle) * length;
    if(parent)
    {
        parent->drag(this->x, this->y);
    }
}