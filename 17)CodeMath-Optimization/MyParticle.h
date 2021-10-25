#ifndef MYPARTICLE
#define MYPARTICLE

#include "MyVector.h"

class MyParticle
{
public:
    float x;
    float y;
    float vx;
    float vy;
    float gravity;
    float mass;
    float radius;
    float bounce;
    float friction;

    //constructors destructors---------------------------------------
    MyParticle() :x{0}, y{0}, vx{0}, vy{0}, gravity{0}, mass{0}, radius{0}, bounce{-1}, friction{1} {}
    MyParticle(float x, float y, float speed, float direction, float mass = 1, float gravity = 0, float radius = 0, float bounce = -1, float friction = 1);
    ~MyParticle() {}

    void Accelerate(float ax, float ay);

    void Move();

    float AngleTo(const MyParticle& p2);

    float DistanceTo(const MyParticle& p2);

    void GravitateTo(const MyParticle& p2);
};

void spring(MyParticle& p1, MyParticle& p2, float separation, float k);
void setBoundaies(MyParticle& point, float width, float height);

namespace utl
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
}

#endif