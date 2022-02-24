#include "raylib.h"
#include <iostream>
#include "star.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    Star a(width/2, height/2);
    Star b(width/2 - 200, height/2);

    while (!WindowShouldClose())
    {
        a.pos.x = GetMousePosition().x;
        a.pos.y = GetMousePosition().y;
        BeginDrawing();
        ClearBackground(WHITE);
        a.draw();
        a.update();
        b.draw();
        b.update();

        a.isCollidingWith(b);

        EndDrawing();
    }
    
}