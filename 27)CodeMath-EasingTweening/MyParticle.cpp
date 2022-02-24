#include "MyParticle.h"
#include <math.h>

MyParticle::MyParticle(float x, 
                       float y, 
                       float speed, 
                       float direction, 
                       float mass, 
                       float gravity, 
                       float radius, 
                       float bounce, 
                       float friction)
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
    this->handleSprings();
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

void MyParticle::addGravitation(MyParticle& point)
{
    this->removeGravitation(point);
    gravitysArray.push_back(&point);
}

void MyParticle::removeGravitation(MyParticle& point)
{
    int arraySize = gravitysArray.size();
    if(arraySize > 0)
    {
        for(int i = 0; i < arraySize; ++i)
        {
            if(&point == gravitysArray[i])
            {
                gravitysArray.erase(gravitysArray.begin() + i);
                return;
            }
        }
    }
}

void MyParticle::handleGravitys()
{
    for(int i = 0; i < int(gravitysArray.size()); ++i)
    {
        this->GravitateTo(*gravitysArray[i]);
    }
}

void MyParticle::SpringTo(MyVector& p2, float k, float lenght)
{
    float dx = p2.x - this->x;
    float dy = p2.y - this->y;
    float distance = sqrt(dx * dx + dy * dy);
    float springForce = (distance - lenght) * k;
    this->vx += (dx / distance) * springForce;
    this->vy += (dy / distance) * springForce;
}

void MyParticle::addSpring(MyVector& point, float k, float lenght)
{
    this->removeSpring(point);
    Spring var(&point, k, lenght);
    springsArray.push_back(var);
}

void MyParticle::removeSpring(MyVector& point)
{
    int arraySize = springsArray.size();
    if(int(arraySize > 0))
    {
        for(int i = 0; i < arraySize; ++i)
        {
            if(&point == springsArray[i].sprTo)
            {
                springsArray.erase(springsArray.begin() + i);
                return;
            }
        }
    }
}

void MyParticle::handleSprings()
{
    for(int i = 0; i < int(springsArray.size()); ++i)
    {
        Spring spring = springsArray[i];
        this->SpringTo(*spring.sprTo, spring.k, spring.separation);
    }
}

float MyParticle::getSpeed()
{
    return sqrt(x*x + y*y);
}

float MyParticle::getHeading()
{
    return atan2(y, x);
}

void MyParticle::setSpeed(float speed)
{
    float heading = this->getHeading();

    vx = cos(heading) * speed;
    vy = sin(heading) * speed;
}

void MyParticle::setHeading(float angle)
{
    float speed = this->getSpeed();

    vx = cos(angle) * speed;
    vy = sin(angle) * speed;
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