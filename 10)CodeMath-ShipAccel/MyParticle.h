#ifndef MYPARTICLE
#define MYPARTICLE

#include "MyVector.h"

class MyParticle
{
private:
    MyVector position;
    MyVector velocity;
    MyVector gravity;
public:
    MyParticle() {}
    MyParticle(float x, float y, float speed, float direction, float gravity = 0);

    const MyVector& GetPosition() const;

    const MyVector& GetVelocity() const;

    void SetAll(float x, float y, float speed, float direction, float gravity = 0);

    void SetPosition(float x, float y);

    void SetX(float x);

    void SetY(float y);

    void SetGravity(const MyVector& gravity);

    void Accelerate(const MyVector& acceleration);

    void Move();

    ~MyParticle() {}


};


#endif