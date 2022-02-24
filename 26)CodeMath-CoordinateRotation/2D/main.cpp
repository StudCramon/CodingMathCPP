#include "raylib.h"
#include <math.h>

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    Vector2 center{width/2, height/2};

    Vector2 point{200, 300};
    float delta = 0.05;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawCircle(point.x + center.x, point.y + center.y, 20, BLUE);

        float nX = point.x * cos(delta) - point.y * sin(delta);
        float ny = point.y * cos(delta) + point.x * sin(delta);

        point.x = nX;
        point.y = ny;

        EndDrawing();
    }
    
}