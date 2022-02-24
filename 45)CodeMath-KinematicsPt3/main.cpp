#include "raylib.h"
#include "Arm.h"
#include "IKSystem.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    //SetTargetFPS(240);

    IKSystem iks(width/2, height/2);
    
    int numOfSegments = 2500;
    int lenghtOfSegments = 1;

    for(int i = 0; i < numOfSegments; ++i)
    {
        iks.addArm(lenghtOfSegments);
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        iks.drag(GetMousePosition().x, GetMousePosition().y);
        iks.draw();
        

        EndDrawing();
    }
    
}