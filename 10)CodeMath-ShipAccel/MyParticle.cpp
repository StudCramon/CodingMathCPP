#include "MyParticle.h"

MyParticle::MyParticle(float x, float y, float speed, float direction, float gravity) 
{
    position.setX(x);
    position.setY(y);
    velocity.setLenght(speed);
    velocity.setAngle(direction);
    this->gravity = MyVector(0, gravity);
}

const MyVector& MyParticle::GetPosition() const 
{
    return position;
}

const MyVector& MyParticle::GetVelocity() const 
{
    return velocity;
}

void MyParticle::SetAll(float x, float y, float speed, float direction, float gravity) 
{
    position.setX(x);
    position.setY(y);
    velocity.setLenght(speed);
    velocity.setAngle(direction);
    this->gravity = MyVector(0, gravity);
}

void MyParticle::SetPosition(float x, float y) 
{
    position.setX(x);
    position.setY(y);
}

void MyParticle::SetX(float x) 
{
    position.setX(x);
}

void MyParticle::SetY(float y) 
{
    position.setY(y);
}

void MyParticle::SetGravity(const MyVector& gravity)
{
    this->gravity = gravity;
}

void MyParticle::Accelerate(const MyVector& acceleration) 
{
    velocity += acceleration;
}

void MyParticle::Move() 
{
    velocity += gravity;
    position += velocity;
}
