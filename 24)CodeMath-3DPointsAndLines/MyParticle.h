#ifndef MYPARTICLE
#define MYPARTICLE

#include "MyVector.h"
#include <vector>

class MyParticle;

struct Spring
{
    MyVector* sprTo;
    float k;
    float separation;
    Spring(MyVector* adrs, float stiff, float lenght) {sprTo = adrs; k = stiff; separation = lenght;}
};

class MyParticle : public MyVector
{
private:
    std::vector<Spring> springsArray;
    std::vector<MyParticle*> gravitysArray;

    void handleSprings();
public:
    float vx;
    float vy;
    float gravity;
    float mass;
    float radius;
    float bounce;
    float friction;

    //constructors destructors---------------------------------------
    MyParticle() : MyVector(0, 0), vx{0}, vy{0}, gravity{0}, mass{0}, radius{0}, bounce{-1}, friction{1} {}
    MyParticle(float x, float y, float speed, float direction, float mass = 1, float gravity = 0, float radius = 0, float bounce = -1, float friction = 1);
    ~MyParticle() {}

    void Accelerate(float ax, float ay);

    void Move();

    float AngleTo(const MyParticle& p2);

    float DistanceTo(const MyParticle& p2);

    void GravitateTo(const MyParticle& p2);

    void addGravitation(MyParticle& point);

    void removeGravitation(MyParticle& point);

    void handleGravitys();

    void SpringTo(MyVector& p1, float k, float lenght = 0);

    void addSpring(MyVector& point, float k, float lenght = 0);

    void removeSpring(MyVector& point);

    float getSpeed();

    float getHeading();

    void setSpeed(float speed);

    void setHeading(float angle);
};

void setBoundaies(MyParticle& CenterPoint, float width, float height);

#endif