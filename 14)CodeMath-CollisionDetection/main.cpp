#include <vector>
#include "raylib.h"
#include "MyVector.h"
#include "MyParticle.h"

void RemoveDeadParticles(std::vector<MyParticle>& particles);

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    MyVector center(width/2, height/2);

    std::vector<MyParticle> particles;
    particles.resize(10);
    for(int i = particles.size() - 1; i >= 0; --i)
    {
        particles[i].SetAll(center.getX(), center.getY(), 100, - PI / 2, 1, 1, 10, -0.9, 0.99);
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        for(int i = particles.size() - 1; i >= 0; --i)
        {
            DrawCircle(particles[i].GetPosition().getX(), particles[i].GetPosition().getY(), particles[i].GetRadius(), GREEN);

            if(particles[i].GetPosition().getX() + particles[i].GetRadius() > width)
            {
                particles[i].SetX(width - particles[i].GetRadius());
                particles[i].SetVelX(particles[i].GetVelocity().getX() * particles[i].GetBounce());
            }
            if(particles[i].GetPosition().getX() - particles[i].GetRadius() < 0)
            {
                particles[i].SetX(particles[i].GetRadius());
                particles[i].SetVelX(particles[i].GetVelocity().getX() * particles[i].GetBounce());
            }
            if(particles[i].GetPosition().getY() + particles[i].GetRadius() > height)
            {
                particles[i].SetY(height - particles[i].GetRadius());
                particles[i].SetVelY(particles[i].GetVelocity().getY() * particles[i].GetBounce());
            }
            if(particles[i].GetPosition().getY() - particles[i].GetRadius() < 0)
            {
                particles[i].SetY(particles[i].GetRadius());
                particles[i].SetVelY(particles[i].GetVelocity().getY() * particles[i].GetBounce());
            }

            particles[i].Accelerate(particles[i].GetGravity());
            particles[i].Move();
        }

        //RemoveDeadParticles(particles);

        EndDrawing();
    }
    
}

void RemoveDeadParticles(std::vector<MyParticle>& particles)
{
    for(int i = particles.size() - 1; i >= 0; --i)
    {
        if(particles[i].GetPosition().getX() > 1280 +  2 * particles[i].GetRadius() ||
            particles[i].GetPosition().getX() < 0 - 2 * particles[i].GetRadius() ||
            particles[i].GetPosition().getY() > 720 + 2 * particles[i].GetRadius() ||
            particles[i].GetPosition().getY() < 0 - 2 * particles[i].GetRadius())
            {
                particles.erase(particles.begin() + i);
            }
    }
}