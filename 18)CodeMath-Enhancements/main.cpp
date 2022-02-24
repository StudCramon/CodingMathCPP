#include "raylib.h"
#include "MyParticle.h"
#include "MyUtility.h"


int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    MyVector center(width/2, height/2);

    MyParticle point(center.x, center.y, 0, 0);
    MyParticle weight(Util::getRand1f() * width, Util::getRand1f() * height, 0, 0);
    weight.gravity = 10;
    weight.friction = 0.9;
    weight.radius = 20;
    point.radius = 2;

    weight.addSpring(center, 0.1, 100);
    weight.addSpring(point, 0.1, 100);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        weight.Move();
        point.x = GetMousePosition().x;
        point.y = GetMousePosition().y;


        DrawCircle(point.x, point.y, point.radius, BLACK);
        DrawCircle(center.x, center.y, point.radius, BLACK);
        DrawCircle(weight.x, weight.y, weight.radius, GREEN);
        DrawLine(point.x, point.y, weight.x, weight.y, BLACK);
        DrawLine(center.x, center.y, weight.x, weight.y, BLACK);

        EndDrawing();
    }
    
}