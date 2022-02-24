#include "raylib.h"
#include "MyParticle.h"
#include "MyUtility.h"
#include <iostream>

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(25);
    MyVector p0(Util::getRand1f() * width, Util::getRand1f() * height);
    MyVector p1(Util::getRand1f() * width, Util::getRand1f() * height);
    MyVector p2(Util::getRand1f() * width, Util::getRand1f() * height);
    MyVector p3(Util::getRand1f() * width, Util::getRand1f() * height);
    MyVector pStart;
    MyVector pFinish;
    RenderTexture2D target = LoadRenderTexture(width, height);

    Util::cubicBezier(p0, p1, p2, p3, 0, pStart);
    float i = 0;


    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        i += 0.01;
        if(i > 1)
        {
            i = 0;
            Util::cubicBezier(p0, p1, p2, p3, i, pStart);
            continue;
        }
        Util::cubicBezier(p0, p1, p2, p3, i, pFinish);

        BeginTextureMode(target);
        DrawLine(pStart.x, pStart.y, pFinish.x, pFinish.y, BLACK);
        DrawCircle(p0.x, p0.y, 10, BLUE);
        DrawCircle(p1.x, p1.y, 10, RED);
        DrawCircle(p2.x, p2.y, 10, RED);
        DrawCircle(p3.x, p3.y, 10, BLUE);

        EndTextureMode();
        pStart = pFinish;

        DrawTexture(target.texture, 0, 0, WHITE);


        EndDrawing();
    }
}