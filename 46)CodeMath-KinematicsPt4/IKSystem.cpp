#include "IKSystem.h"

void IKSystem::addArm(float length)
{
    arms.push_back(new Arm(0, 0, length, 0));
    size_t newArmIndex = arms.size() - 1;
    if(lastArm)
    {
        arms[newArmIndex]->x = lastArm->getEndX();
        arms[newArmIndex]->y = lastArm->getEndY();
        arms[newArmIndex]->parent = lastArm;
    }
    else
    {
        arms[newArmIndex]->x = x;
        arms[newArmIndex]->y = y;
    }
    lastArm = arms[newArmIndex];
}

void IKSystem::draw()
{
    for(size_t i = 0; i < arms.size(); ++i)
    {
        arms[i]->draw();
    }
}

void IKSystem::drag(float x, float y)
{
    lastArm->drag(x, y);
}

void IKSystem::reach(float x, float y)
{
    this->drag(x, y);
    this->update();
}

void IKSystem::update()
{
    for(size_t i = 0; i < arms.size(); ++i)
    {
        if(arms[i]->parent)
        {
            arms[i]->x = arms[i]->parent->getEndX();
            arms[i]->y = arms[i]->parent->getEndY();
        }
        else
        {
            arms[i]->x = x;
            arms[i]->y = y;
        }
    }
}