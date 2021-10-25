#include "MyParticle.h"
#include <math.h>

MyParticle::MyParticle(float x, float y, float speed, float direction, float mass = 1, float gravity = 0, float radius = 0, float bounce = -1, float friction = 1)
{
    this->x = x;
    this->y = y;
    this->vx = cos(direction) * speed;
    this->vy = sin(direction) * speed;
    this->mass = mass;
    this->gravity = gravity;
    this->radius = radius;
    this->bounce = bounce;
    this->friction = friction;
}

void MyParticle::Accelerate(float ax, float ay) 
{
    vx += ax;
    vy += ay;
}

void MyParticle::Move() 
{
    vx *= friction;
    vy *= friction;
    vy += gravity;
    x += vx;
    y += vy;
}

float MyParticle::AngleTo(const MyParticle& p2) 
{
    float dx = p2.x - this->x;
    float dy = p2.y - this->y;
    return atan2(dy, dx);
}

float MyParticle::DistanceTo(const MyParticle& p2) 
{
    float dx = p2.x - this->x;
    float dy = p2.y - this->y;
    return sqrt(dx*dx + dy*dy);
}

void MyParticle::GravitateTo(const MyParticle& p2) 
{
    // MyVector gravity(0, 0);
    // float distance = this->DistanceTo(p2);

    // gravity.setLenght(p2.mass/ (distance * distance));
    // gravity.setAngle(this->AngleTo(p2));

    // this->vx += gravity.getX();
    // this->vy += gravity.getY();

    float dx = p2.x - this->x;
    float dy = p2.y - this->y;
    float dstSQ = dx * dx + dy * dy;
    float dst = sqrt(dstSQ);
    float force = p2.mass * dstSQ;
    float ax = dx/dst * force;
    float ay = dy/dst * force;

    vx += ax;
    vy += ay;

}

void spring(MyParticle& p1, MyParticle& p2, float separation, float k)
{
    // MyVector distance(p1.x - p2.x, p1.y - p2.y);
    // distance.setLenght(distance.getLenght() - separation);

    // MyVector springForce = distance * k;

    // p1.SetVelocity(p1.GetVelocity() - springForce);
    // p2.SetVelocity(p2.GetVelocity() + springForce);
}

void setBoundaies(MyParticle& point, float width, float height)
{
    if(point.x + point.radius > width)
    {
        point.x = width - point.radius;
    }
    if(point.x - point.radius < 0)
    {
        point.x = 0 + point.radius;
    }
    if(point.y + point.radius > height)
    {
        point.y = height - point.radius;
    }
    if(point.y - point.radius < 0)
    {
        point.y = 0 + point.radius;
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