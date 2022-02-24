#include "raylib.h"

float linearTween(float curTime, float startVal, float changeInVal, float duration);
float easeInQuad(float curTime, float startVal, float changeInVal, float duration);
float easeOutQuad(float curTime, float startVal, float changeInVal, float duration);
float easeInOutQuad(float curTime, float startVal, float changeInVal, float duration);

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");

    Vector2 start{100, 100};
    Vector2 target{};
    Vector2 change;
    float startTime;
    float duration = 2;

    while(!WindowShouldClose())
    {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            target.x = GetMousePosition().x;
            target.y = GetMousePosition().y;
            change.x = target.x - start.x;
            change.y = target.y - start.y;
            startTime = GetTime();
        }

        BeginDrawing();
        ClearBackground(WHITE);

        float time = GetTime() - startTime;

        if(time < duration)
        {
            float x = linearTween(time, start.x, change.x, duration);
            float y = linearTween(time, start.y, change.y, duration);
            DrawCircle(x, y, 20, BLUE);
        }
        else
        {
             DrawCircle(target.x, target.y, 20, BLUE);
             start.x = target.x;
             start.y = target.y;
        }

        EndDrawing();
    }
}

float linearTween(float curTime, float startVal, float changeInVal, float duration)
{
    return changeInVal * (curTime/duration) + startVal;
}

float easeInQuad(float curTime, float startVal, float changeInVal, float duration)
{
    return changeInVal * (curTime /= duration) * curTime + startVal;
}

float easeOutQuad(float curTime, float startVal, float changeInVal, float duration)
{
    return -changeInVal * (curTime /= duration) * (curTime - 2) + startVal;
}

float easeInOutQuad(float curTime, float startVal, float changeInVal, float duration)
{
    if((curTime /= duration/2) < 1) return changeInVal/2*curTime*curTime + startVal;
    return -changeInVal/2 * ((--curTime) * (curTime-2)-1) + startVal;
}