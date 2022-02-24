#ifndef MYUTILITY
#define MYUTILITY

#include "MyVector.h"
#include "MyParticle.h"
#include <math.h>

namespace Util
{
    float getRand1f();
    float norm(float value, float min, float max);
    float lerp(float norm, float min, float max);
    float map(float value, float soureceMin, float sourceMax, float destMin, float destMax);
    float clamp(float value, float min, float max);
    float distance(const MyVector& v1, const MyVector& v2);
    bool circleCollision(const MyParticle& c1, const MyParticle& c2);
    bool circlePointCollision(const MyParticle& c1, const MyVector& p1);
    bool pointInRect(const MyVector& p1, const MyVector& r1, float width, float height);
    bool inRange(float value, float min, float max);
    bool rangeIntersect(float min0, float max0, float min1, float max1);
    bool rectIntersect(const MyVector& r1, float width1, float height1, const MyVector& r2, float width2, float height2);
    float degreesToRads(float degrees);
    float radsToDegrees(float radians);
    float roundToPlaces(float value, float places);
    float roundToNearest(float value, float nearest);
}

#endif