#include "raylib.h"
#include "MyUtility.h"
#include <vector>

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(120);
    RenderTexture2D target = LoadRenderTexture(width, height);

    std::vector<MyVector> points;
    for (int i = 0; i < 1000; ++i)
    {
        points.push_back(MyVector(Util::getRand1f() * width, Util::getRand1f() * height));
    }

    BeginTextureMode(target);
    DrawCircle(points[0].x, points[0].y, 10, GREEN);
    DrawCircle(points[points.size() - 1].x, points[points.size() - 1].y, 10, GREEN);
    for(int i = 1; i < int(points.size() - 1); ++i)
    {
        DrawCircle(points[i].x, points[i].y, 10, RED);
    }
    EndTextureMode();

    MyVector pStart;
    MyVector pFinish;

    Util::multiBezier(points, 0, pStart);
    float i = 0;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        i += 0.01;
        if(i > 1)
        {
            i = 0;
            Util::multiBezier(points, i, pStart);
            continue;
        }
        Util::multiBezier(points, i, pFinish);

        BeginTextureMode(target);
        DrawLine(pStart.x, pStart.y, pFinish.x, pFinish.y, BLACK);
        EndTextureMode();
        pStart = pFinish;

        DrawTexture(target.texture, 0, 0, WHITE);


        EndDrawing();
    }
}