#include "raylib.h"
#include <vector>

void trnslToScreen(const Vector2& center, const Vector3& shapePos, float focalLenght, Vector2& pointOut);
void connectPoints(const std::vector<Vector2>& screenPoints, int NumOfPoints, ...);

int main()
{
    float width = 1280;
    float height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    Vector2 centerOfScreen{width/2, height/2};

    float focalLenght = 300;
    int NumOfPoints = 8;
    float speed = 10;
    bool NeedsUpdate = true;
    std::vector<Vector3> points(NumOfPoints);
    std::vector<Vector2> screenPoints(NumOfPoints);

    points[0] = Vector3{-500, -500, 1000};
    points[1] = Vector3{ 500, -500, 1000};
    points[2] = Vector3{ 500, -500, 500};
    points[3] = Vector3{-500, -500, 500};
    points[4] = Vector3{-500, 500, 1000};
    points[5] = Vector3{ 500, 500, 1000};
    points[6] = Vector3{ 500, 500, 500};
    points[7] = Vector3{-500, 500, 500};
    
    while (!WindowShouldClose())
    {   
        if(IsKeyDown(KEY_A))
        {
            for(int i = 0; i < NumOfPoints; ++i)
            {
                points[i].x -= speed;
                NeedsUpdate = true;
            }
        }
        if(IsKeyDown(KEY_D))
        {
            for(int i = 0; i < NumOfPoints; ++i)
            {
                points[i].x += speed;
                NeedsUpdate = true;
            }
        }
        if(IsKeyDown(KEY_W))
        {
            for(int i = 0; i < NumOfPoints; ++i)
            {
                points[i].z += speed;
                NeedsUpdate = true;
            }
        }
        if(IsKeyDown(KEY_S))
        {
            for(int i = 0; i < NumOfPoints; ++i)
            {
                points[i].z -= speed;
                NeedsUpdate = true;
            }
        }
        if(IsKeyDown(KEY_LEFT_SHIFT))
        {
            for(int i = 0; i < NumOfPoints; ++i)
            {
                points[i].y -= speed;
                NeedsUpdate = true;
            }
        }
        if(IsKeyDown(KEY_LEFT_CONTROL))
        {
            for(int i = 0; i < NumOfPoints; ++i)
            {
                points[i].y += speed;
                NeedsUpdate = true;
            }
        }
        if(IsKeyDown(KEY_UP))
        {
            focalLenght += 10;
            NeedsUpdate = true;
        }
        if(IsKeyDown(KEY_DOWN))
        {
            focalLenght -= 10;
            NeedsUpdate = true;
        }

        BeginDrawing();
        ClearBackground(WHITE);

        if(NeedsUpdate)
        {
            for(int i = 0; i < NumOfPoints; ++i)
            {
                trnslToScreen(centerOfScreen, points[i], focalLenght, screenPoints[i]);
            }
            NeedsUpdate = false;
        }

        connectPoints(screenPoints, 5, 0, 1, 2, 3, 0);
        connectPoints(screenPoints, 5, 4, 5, 6, 7, 4);
        connectPoints(screenPoints, 2, 0, 4);
        connectPoints(screenPoints, 2, 1, 5);
        connectPoints(screenPoints, 2, 2, 6);
        connectPoints(screenPoints, 2, 3, 7);

        EndDrawing();
    }
    
}

void trnslToScreen(const Vector2& center, const Vector3& shapePos, float focalLenght, Vector2& pointOut)
{
    float perspective = focalLenght / (focalLenght + shapePos.z);
    pointOut.x = shapePos.x * perspective;
    pointOut.y = shapePos.y * perspective;
    pointOut.x += center.x;
    pointOut.y += center.y;
}

void connectPoints(const std::vector<Vector2>& screenPoints, int NumOfPoints, ...)
{
    va_list listOfPoints;

    va_start(listOfPoints, NumOfPoints);

    int start = va_arg(listOfPoints, int);
    for(int i = 0; i < NumOfPoints-1; ++i)
    {
        int finish = va_arg(listOfPoints, int);
        DrawLine(screenPoints[start].x, screenPoints[start].y, screenPoints[finish].x, screenPoints[finish].y, BLACK);
        start = finish;
    }
    
    va_end(listOfPoints);
}