#include "FKSystem.h"

void FKSystem::addArm(float length, float centerAngle, float rotationRange, float phaseOffset)
{
    arms.push_back(new Arm(length, centerAngle, rotationRange, phaseOffset));
    
    size_t NewlastArmIndex = arms.size() - 1;
    if(lastArm)
    {
        arms[NewlastArmIndex]->parent = lastArm;
    }
    lastArm = arms[NewlastArmIndex];
    this->update(); 
}

void FKSystem::update()
{
    for(size_t i = 0; i < arms.size(); ++i)
    {
        arms[i]->setPhase(phase);
        if(arms[i]->parent)
        {
            arms[i]->x = arms[i]->parent->getEndX();
            arms[i]->y = arms[i]->parent->getEndY();
        }
        else
        {
            arms[i]->x = this->x;
            arms[i]->y = this->y;
        }
    }
    phase += speed;
}

void FKSystem::draw()
{
    for(size_t i = 0; i < arms.size(); ++i)
    {
        arms[i]->draw();
    }
}

void FKSystem::rotate(int index, float angle)
{
    arms[index]->angle = angle;
}