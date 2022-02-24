#include "PhysicsEntity.h"

void PhysEnt::update()
{
    if(isStatic)
    {
        x = GetMousePosition().x;
        y = GetMousePosition().y;
        return;
    }

    float vx = (x - oldx) * friction;
    float vy = (y - oldy) * friction;

    oldx = x;
    oldy = y;

    x += vx;
    y += vy;
    y += gravity;
    checkConstraints();
}

void PhysEnt::draw()
{
    DrawCircle(x, y, 10, BLACK);
}

void PhysEnt::checkConstraints()
{
    if(isStatic)
    {
        return;
    }

    float vx = x - oldx;
    float vy = y - oldy;
    
    if(x > GetScreenWidth())
    {
        x = GetScreenWidth();
        oldx = x + vx * bounce;
    }
    else if(x < 0)
    {
        x = 0;
        oldx = x + vx * bounce;
    }

    if(y > GetScreenHeight())
    {
        y = GetScreenHeight();
        oldy = y + vy * bounce;
    }
    else if(y < 0)
    {
        y = 0;
        oldy = y + vy * bounce;
    }
}