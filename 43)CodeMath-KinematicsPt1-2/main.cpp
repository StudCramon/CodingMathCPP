#include "raylib.h"
#include "Arm.h"
#include "FKSystem.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);

    FKSystem fks(width/2, height/2);
    FKSystem fks2(width/2, height/2);
    
    fks.addArm(200, PI/2, PI/4, 0);
    fks.addArm(180, 0.87, 0.87, -1.5);

    fks2.addArm(200, PI/2, PI/4, 0);
    fks2.addArm(180, 0.87, 0.87, -1.5);
    fks2.phase += PI;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        fks.update();
        fks2.update();
        fks.draw();
        fks2.draw();
        

        EndDrawing();
    }
    
}