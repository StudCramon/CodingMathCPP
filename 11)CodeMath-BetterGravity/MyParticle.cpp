#include "MyParticle.h"
#include <math.h>

MyParticle::MyParticle(float x, float y, float speed, float direction, float mass) 
{
    position.setX(x);
    position.setY(y);
    velocity.setLenght(speed);
    velocity.setAngle(direction);
    this->mass = mass;
}

const MyVector& MyParticle::GetPosition() const 
{
    return position;
}

const MyVector& MyParticle::GetVelocity() const 
{
    return velocity;
}

void MyParticle::SetAll(float x, float y, float speed, float direction, float mass) 
{
    position.setX(x);
    position.setY(y);
    velocity.setLenght(speed);
    velocity.setAngle(direction);
    this->mass = mass;
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

void MyParticle::Accelerate(const MyVector& acceleration) 
{
    velocity += acceleration;
}

void MyParticle::Move() 
{
    position += velocity;
}

float MyParticle::AngleTo(const MyParticle& p2) 
{
    float dx = p2.GetPosition().getX() - this->position.getX();
    float dy = p2.GetPosition().getY() - this->position.getY();
    return atan2(dy, dx);
}

float MyParticle::DistanceTo(const MyParticle& p2) 
{
    float dx = p2.GetPosition().getX() - this->position.getX();
    float dy = p2.GetPosition().getY() - this->position.getY();
    return sqrt(dx*dx + dy*dy);
}

void MyParticle::GravitateTo(const MyParticle& p2) 
{
    MyVector gravity(0, 0);
    float distance = this->DistanceTo(p2);

    gravity.setLenght(p2.mass/ (distance * distance));
    gravity.setAngle(this->AngleTo(p2));

    this->velocity += gravity;
}
