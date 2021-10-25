#include "raylib.h"
#include "MyParticle.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    MyVector center(width/2, height/2);
    MyParticle weight(utl::getRand1f() * width, utl::getRand1f() * height, 0, 0);
    weight.SetRadius(20);
    weight.SetFriction(0.99);
    float k = 0.1;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        MyVector springPoint(GetMousePosition().x, GetMousePosition().y);
        MyVector distance = springPoint - weight.GetPosition();
        MyVector springForce = distance * k;
        weight.SetVelocity(weight.GetVelocity() + springForce);
        weight.Move();
        DrawCircle(weight.GetPosition().getX(), weight.GetPosition().getY(), weight.GetRadius(), GREEN);
        DrawCircle(springPoint.getX(), springPoint.getY(), 2, BLACK);
        DrawLine(springPoint.getX(), springPoint.getY(), weight.GetPosition().getX(), weight.GetPosition().getY(), BLACK);
        EndDrawing();
    }
    

    return 0;
}