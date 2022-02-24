#ifndef MYUTILITY
#define MYUTILITY

#include "MyVector.h"
#include "MyParticle.h"
#include <math.h>
#include <vector>

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

    void quadraticBezier(MyVector& p0, MyVector& p1, MyVector& p2, float t, MyVector& Outp);

    void cubicBezier(const MyVector& p0, const MyVector& p1, const MyVector& p2, const MyVector& p3, float t, MyVector& pOut);

    void multiBezier(const std::vector<MyVector>& points, float t, MyVector& pOut);
}

#endif