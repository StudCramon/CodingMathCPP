#include "raylib.h"

void lineIntersect(const Vector2& p11, const Vector2& p12, const Vector2& p21, const Vector2& p22, Vector2& outPoint);

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        EndDrawing();
    }
    
}

void lineIntersect(const Vector2& p11, const Vector2& p12, const Vector2& p21, const Vector2& p22, Vector2& outPoint)
{
    float A1 = p12.y - p11.y;
    float B1 = p11.x - p12.x;
    float C1 = A1 * p11.x + B1 * p11.y;

    float A2 = p22.y - p21.y;
    float B2 = p21.x - p22.x;
    float C2 = A2 * p21.x + B2 * p21.y;

    float denominator = A1 * B2 - A2 * B1;

    outPoint.x = (B2 * C1 - B1 * C2) / denominator;
    outPoint.y = (A1 * C2 - A2 * C1) / denominator;
}