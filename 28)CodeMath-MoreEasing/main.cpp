#include "raylib.h"
#include "MyUtility.h"
#include <math.h>

bool easeTo(const Vector2& target, float ease, Vector2& OutPoint);

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);

    Vector2 target{width, Util::getRand1f() * height};
    Vector2 position{0, Util::getRand1f() * height};
    float ease = 0.1;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            target.x = GetMousePosition().x;
            target.y = GetMousePosition().y;
        }

        DrawCircle(position.x, position.y, 10, BLUE);

        easeTo(target, ease, position);

        EndDrawing();
    }
    
}

bool easeTo(const Vector2& target, float ease, Vector2& OutPoint)
{
    float dx = target.x - OutPoint.x;
    float dy = target.y - OutPoint.y;
    
    if(abs(dx) < 0.1 && abs(dy) < 0.1)
    {
        OutPoint.x = target.x;
        OutPoint.y = target.y;
        return false;
    }
    
    OutPoint.x += dx * ease;
    OutPoint.y += dy * ease;
    return true;
}