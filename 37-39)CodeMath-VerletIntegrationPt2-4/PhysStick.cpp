#include "PhysStick.h"

Stick::Stick(PhysEnt* p1, PhysEnt* p2)
{
    this->p1 = p1;
    this->p2 = p2;

    if(p1 && p2)
    {
        float dx = this->p2->x - this->p1->x;
        float dy = this->p2->y - this->p1->y;
        lenght = sqrt(dx * dx + dy * dy);
        std::cout << lenght << std::endl;
    }
}

void Stick::update(int percision)
{  
    for(int i = 0; i < percision; ++i)
    {
        float dx = p2->x - p1->x;
        float dy = p2->y - p1->y;
        float distance = sqrt(dx*dx + dy*dy);
        float difference = lenght - distance;
        float percent = (difference/distance)/2;
        float offsetX = dx * percent;
        float offsetY = dy * percent;

        if(!p1->isStatic)
        {
            p1->x -= offsetX;
            p1->y -= offsetY;
            p1->checkConstraints();
        }

        if(!p2->isStatic)
        {
            p2->x += offsetX;
            p2->y += offsetY;
            p2->checkConstraints();
        }
    }
}

void Stick::draw()
{
    if(!isHidden)
    {
        DrawLineEx(Vector2{p1->x, p1->y}, Vector2{p2->x, p2->y}, thick, stickColor);
    }
}