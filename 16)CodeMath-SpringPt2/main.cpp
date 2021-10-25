#include "raylib.h"
#include "MyParticle.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    MyVector center(width/2, height/2);

    
    MyParticle point(center.getX(), center.getY(), 0, 0);
    point.SetRadius(20);
    point.SetFriction(0.9);
    point.SetGravity(0.5);
    MyParticle weight(utl::getRand1f() * width, utl::getRand1f() * height, 0, 0);
    weight.SetRadius(20);
    weight.SetFriction(0.9);
    weight.SetGravity(0.5);
    MyParticle circle(utl::getRand1f() * width, utl::getRand1f() * height, 0, 0);
    circle.SetRadius(20);
    circle.SetFriction(0.9);
    circle.SetGravity(0.5);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        spring(point, weight, 100 , 0.1);
        spring(weight, circle, 100, 0.1);
        spring(circle, point, 100, 0.1);

       setBoundaies(weight, width, height);
       setBoundaies(point, width, height);
       setBoundaies(circle, width, height);

        DrawLine(weight.GetPosition().getX(), weight.GetPosition().getY(), point.GetPosition().getX(), point.GetPosition().getY(), BLACK);
        DrawLine(weight.GetPosition().getX(), weight.GetPosition().getY(), circle.GetPosition().getX(), circle.GetPosition().getY(), BLACK);
        DrawLine(circle.GetPosition().getX(), circle.GetPosition().getY(), point.GetPosition().getX(), point.GetPosition().getY(), BLACK);
        DrawCircle(weight.GetPosition().getX(), weight.GetPosition().getY(), weight.GetRadius(), BLUE);
        DrawCircle(point.GetPosition().getX(), point.GetPosition().getY(), point.GetRadius(), GREEN);
        DrawCircle(circle.GetPosition().getX(), circle.GetPosition().getY(), circle.GetRadius(), RED);
        
        weight.Move();
        point.Move();
        circle.Move();

        EndDrawing();
    }
    

    return 0;
}