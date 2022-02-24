#include "raylib.h"
#include "MyUtility.h"

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

        float dx = target.x - position.x;
        float dy = target.y - position.y;
        float vx = dx * ease;
        float vy = dy * ease;

        position.x += vx;
        position.y += vy;

        EndDrawing();
    }
    
}