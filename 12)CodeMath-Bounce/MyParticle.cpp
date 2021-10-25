#include "MyParticle.h"
#include <math.h>

MyParticle::MyParticle(float x, float y, float speed, float direction, float mass, float gravity, float radius, float bounce) 
{
    position.setX(x);
    position.setY(y);
    velocity.setLenght(speed);
    velocity.setAngle(direction);
    this->gravity.setY(gravity);
    this->mass = mass;
    this->radius = radius;
    this->bounce = bounce;
}

const MyVector& MyParticle::GetPosition() const 
{
    return position;
}

const MyVector& MyParticle::GetVelocity() const 
{
    return velocity;
}

const MyVector& MyParticle::GetGravity() const
{
    return gravity;
}

float MyParticle::GetMass() const
{
    return mass;
}

float MyParticle::GetRadius() const
{
    return radius;
}

float MyParticle::GetBounce() const
{
    return bounce;
}

void MyParticle::SetAll(float x, float y, float speed, float direction, float mass, float gravity, float radius, float bounce) 
{
    position.setX(x);
    position.setY(y);
    velocity.setLenght(speed);
    velocity.setAngle(direction);
    this->gravity.setY(gravity);
    this->mass = mass;
    this->radius = radius;
    this->bounce = bounce;
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

void MyParticle::SetMass(float mass) 
{
    this->mass = mass;
}

void MyParticle::SetVelocity(float speed, float direction) 
{
    this->velocity.setLenght(speed);
    this->velocity.setAngle(direction);
}

void MyParticle::SetSpeed(float speed)
{
    velocity.setLenght(speed);
}

void MyParticle::SetAngle(float angle)
{
    velocity.setAngle(angle);
}

void MyParticle::SetVelX(float x)
{
    velocity.setX(x);
}

void MyParticle::SetVelY(float y)
{
    velocity.setY(y);
}

void MyParticle::SetGravity(float gravity) 
{
    this->gravity.setY(gravity);
}

void MyParticle::SetGravity(const MyVector& gravity) 
{
    this->gravity = gravity;
}

void MyParticle::SetRadius(float radius)
{
    this->radius = radius;
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

float getRand1f()
{
    float number = (rand()%1000 + 1) * 0.001;
    return number;
}