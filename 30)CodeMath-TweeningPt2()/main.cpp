#include "raylib.h"

float easeInOutQuad(float curTime, float startVal, float changeInVal, float duration)
{
    if((curTime /= duration/2) < 1) return changeInVal/2*curTime*curTime + startVal;
    return -changeInVal/2 * ((--curTime) * (curTime-2)-1) + startVal;
}

void tween(Vector2& object,
           const Vector2& destination,
           float duration,
           float (*easingFunc)(float, float, float, float))
{
    
}


int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    Vector2 ball{100, 100};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        


        EndDrawing();
    }
    
}