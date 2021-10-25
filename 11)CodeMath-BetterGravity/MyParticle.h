#ifndef MYPARTICLE
#define MYPARTICLE

#include "MyVector.h"

class MyParticle
{
private:
    MyVector position;
    MyVector velocity;
    float mass;
public:
    MyParticle() {}
    MyParticle(float x, float y, float speed, float direction, float mass = 1);

    const MyVector& GetPosition() const;

    const MyVector& GetVelocity() const;

    void SetAll(float x, float y, float speed, float direction, float mass);

    void SetPosition(float x, float y);

    void SetX(float x);

    void SetY(float y);

    void Accelerate(const MyVector& acceleration);

    void Move();

    float AngleTo(const MyParticle& p2);

    float DistanceTo(const MyParticle& p2);

    void GravitateTo(const MyParticle& p2);

    ~MyParticle() {}


};


#endif