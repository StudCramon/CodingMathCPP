#ifndef __ARM_H__
#define __ARM_H__

#include "raylib.h"
#include <math.h>

class Arm{
public:
    float x = 0;
    float y = 0;
    float length = 100;
    float angle = 0;
    Arm* parent = nullptr;

    Arm(float x, float y, float length, float angle):
    x{x}, y{y}, length{length}, angle{angle} {}

    float getEndX();
    float getEndY();

    void draw();
    void pointAt(float x, float y);
    void drag(float x, float y);

};

#endif // __ARM_H__