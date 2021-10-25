#include "raylib.h"
#include <math.h>
#include "MyVector.h"
#include "MyParticle.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    MyParticle sun(width/2, height/2, 0, 0, 3000);
    MyParticle planet(width/2 + 200, height/2, 3, -PI/2);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        planet.GravitateTo(sun);
        planet.Move();

        DrawCircle(sun.GetPosition().getX(), sun.GetPosition().getY(), 50, YELLOW);
        DrawCircle(planet.GetPosition().getX(), planet.GetPosition().getY(), 10, BLUE);

        EndDrawing();
    }
    
}