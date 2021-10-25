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

float getRand1f();

#endif