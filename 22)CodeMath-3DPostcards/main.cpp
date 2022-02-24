#include "raylib.h"
#include <string>

Vector3 trnsl(const Vector2& center, const Vector3& shapePos, float focalLenght);

int main()
{
    setlocale(LC_ALL, "Russian");
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);

    float focalLenght = 300;
    Vector2 center{width/2, height/2};
    Vector3 shapePos{100, 100, 300};
    Vector3 changedPos;


    while (!WindowShouldClose())
    {
        changedPos = trnsl(center, shapePos, focalLenght);
        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(changedPos.x, changedPos.y, 20*(focalLenght / (focalLenght + changedPos.z)), BLACK);
        EndDrawing();
        shapePos.z -= 10;
    }
    
}

Vector3 trnsl(const Vector2& center, const Vector3& shapePos, float focalLenght)
{
    Vector3 returnPos = shapePos;
    float perspective = focalLenght / (focalLenght + shapePos.z);
    returnPos.x *= perspective;
    returnPos.y *= perspective;
    returnPos.x += center.x;
    returnPos.y += center.y;
    return returnPos;
}