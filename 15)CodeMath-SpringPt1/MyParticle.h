#ifndef MYPARTICLE
#define MYPARTICLE

#include "MyVector.h"

class MyParticle
{
private:
    MyVector position;
    MyVector velocity;
    MyVector gravity;
    float mass;
    float radius;
    float bounce;
    float friction;
public:
    //constructors destructors---------------------------------------
    MyParticle() {}
    MyParticle(float x, float y, float speed, float direction, float mass = 1, float gravity = 0, float radius = 0, float bounce = -1, float friction = 1);
    ~MyParticle() {}
    //getters---------------------------------------------
    const MyVector& GetPosition() const;

    const MyVector& GetVelocity() const;

    const MyVector& GetGravity() const;

    float GetMass() const;

    float GetRadius() const;

    float GetBounce() const;

    float GetFriction() const;
    //setters------------------------------------------------------
    void SetAll(float x, float y, float speed, float direction, float mass, float gravity, float radius, float bounce, float friction);

    void SetPosition(float x, float y);

    void SetX(float x);

    void SetY(float y);

    void SetMass(float mass);

    void SetVelocity(const MyVector& velocity);

    void SetVelocity(float speed, float direction);

    void SetSpeed(float speed);

    void SetAngle(float angle);

    void SetVelX(float x);

    void SetVelY(float y);

    void SetGravity(float gravity);

    void SetGravity(const MyVector& gravity);

    void SetRadius(float radius);

    void SetBounce(float bounce);

    void SetFriction(float friction);
    //functionality-----------------------------------------------------
    void Accelerate(const MyVector& acceleration);

    void Move();

    float AngleTo(const MyParticle& p2);

    float DistanceTo(const MyParticle& p2);

    void GravitateTo(const MyParticle& p2);
};

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