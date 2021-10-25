#include "MyParticle.h"
#include <math.h>

MyParticle::MyParticle(float x, float y, float speed, float direction, float mass, float gravity, float radius, float bounce, float friction) 
{
    position.setX(x);
    position.setY(y);
    velocity.setLenght(speed);
    velocity.setAngle(direction);
    this->gravity.setY(gravity);
    this->mass = mass;
    this->radius = radius;
    this->bounce = bounce;
    this->friction = friction;
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

float MyParticle::GetFriction() const
{
    return friction;
}

void MyParticle::SetAll(float x, float y, float speed, float direction, float mass, float gravity, float radius, float bounce, float friction) 
{
    position.setX(x);
    position.setY(y);
    velocity.setLenght(speed);
    velocity.setAngle(direction);
    this->gravity.setY(gravity);
    this->mass = mass;
    this->radius = radius;
    this->bounce = bounce;
    this->friction = friction;
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

void MyParticle::SetVelocity(const MyVector& velocity)
{
    this->velocity = velocity;
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

void MyParticle::SetBounce(float bounce)
{
    this->bounce = bounce;
}

void MyParticle::SetFriction(float friction)
{
    this->friction = friction;
}

void MyParticle::Accelerate(const MyVector& acceleration) 
{
    velocity += acceleration;
}

void MyParticle::Move() 
{
    velocity *= friction;
    velocity += gravity;
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

void spring(MyParticle& p1, MyParticle& p2, float separation, float k)
{
    MyVector distance = p1.GetPosition() - p2.GetPosition();
    distance.setLenght(distance.getLenght() - separation);

    MyVector springForce = distance * k;

    p1.SetVelocity(p1.GetVelocity() - springForce);
    p2.SetVelocity(p2.GetVelocity() + springForce);
}

void setBoundaies(MyParticle& point, float width, float height)
{
    if(point.GetPosition().getX() + point.GetRadius() > width)
    {
        point.SetX(width - point.GetRadius());
    }
    if(point.GetPosition().getX() - point.GetRadius() < 0)
    {
        point.SetX(0 + point.GetRadius());
    }
    if(point.GetPosition().getY() + point.GetRadius() > height)
    {
        point.SetY(height - point.GetRadius());
    }
    if(point.GetPosition().getY() - point.GetRadius() < 0)
    {
        point.SetY(0 + point.GetRadius());
    }
}

float utl::getRand1f()
{
    float number = (rand()%1000 + 1) * 0.001;
    return number;
}

float utl::norm(float value, float min, float max)
{
    return (value - min)/(value - max);
}

float utl::lerp(float norm, float min, float max)
{
    return (max - min) * norm + min;
}

float utl::map(float value, float sourceMin, float sourceMax, float destMin, float destMax)
{
    float n = norm(value, sourceMin, sourceMax);
    return lerp(n, destMin, destMax);
}

float utl::clamp(float value, float min, float max)
{
    float val = std::fmax(value, fmin(min, max));
    return std::fmin(val, fmax(min, max));
}

float utl::distance(const MyVector& v1, const MyVector& v2)
{
    float dx = v1.getX() - v2.getX();
    float dy = v1.getY() - v2.getY();
    return sqrt(dx * dx + dy * dy);
}

bool utl::circleCollision(const MyParticle& c1, const MyParticle& c2)
{
    return distance(c1.GetPosition(), c2.GetPosition()) <= c1.GetRadius() + c2.GetRadius();
}

bool utl::circlePointCollision(const MyParticle& c1, const MyVector& p1)
{
    return distance(c1.GetPosition(), p1) < c1.GetRadius();
}

bool utl::pointInRect(const MyVector& p1, const MyVector& r1, float width, float height)
{
    return inRange(p1.getX(), r1.getX(), r1.getX() + width) && 
           inRange(p1.getY(), r1.getY(), r1.getY() + height);
}
    
bool utl::inRange(float value, float min, float max)
{
    return value >= fmin(min, max) && value <= fmax(min, max);
}

bool utl::rangeIntersect(float min0, float max0, float min1, float max1)
{
    return fmax(min0, max0) >= fmin(min1, max1) && 
           fmin(min0, max0) <= fmax(min1, max1);
}

bool utl::rectIntersect(const MyVector& r1, float width1, float height1, const MyVector& r2, float width2, float height2)
{
    return rangeIntersect(r1.getX(), r1.getX() + width1, r2.getX(), r2.getX() + width2) &&
           rangeIntersect(r1.getY(), r1.getY() + height1, r2.getY(), r2.getY() + height2);
           
}

float utl::degreesToRads(float degrees)
{
    return degrees / (180 * 3.1415926535f);
}

float utl::radsToDegrees(float radians)
{
    return (radians * 180) / 3.1415926535f;
}