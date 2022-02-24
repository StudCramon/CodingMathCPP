#include "raylib.h"
#include <vector>
#include <math.h>
#include "MyUtility.h"

Vector3 trnsl(const Vector2& center, const Vector3& shapePos, float focalLenght);

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);

    Vector2 center{width/2, height/2};
    float centerZ = 1500;
    float offsetFromY = 1000;
    float focalLenght = 300;
    float numOfObjects = 1000;
    float baseAngle = 0;
    float rotationSpeed = 0.00005;
    float numOfCircles = 10;
    
    std::vector<Vector3> positions(numOfObjects);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        for(int i = 0; i < numOfObjects; ++i)
        {
            float angle = ((2 * PI * numOfCircles)/numOfObjects) * i;
            angle += baseAngle;
            positions[i].x = cos(angle + baseAngle) * offsetFromY;
            positions[i].y = ((height * numOfCircles/numOfObjects) * i - (height/2) * numOfCircles);
            positions[i].z = (sin(angle + baseAngle) * offsetFromY) + centerZ;

            Vector3 changedPos = trnsl(center, positions[i], focalLenght);
            
            //float perspective = focalLenght / (focalLenght + positions[i].z);
            //DrawCircle(changedPos.x, changedPos.y, 10 * perspective, RED);
            if(!(i == numOfObjects - 1))
            {
                Vector3 changedPosOld = trnsl(center, positions[i + 1], focalLenght);
                DrawLine(changedPosOld.x, changedPosOld.y, changedPos.x, changedPos.y, BLACK);
            }

            baseAngle += rotationSpeed;
        }
        EndDrawing();
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