#include "raylib.h"
#include <vector>
#include "PhysicsEntity.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    std::vector<PhysEnt> points;
    points.push_back(PhysEnt(100, 100, 95, 95));

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for(size_t i = 0; i < points.size(); ++i)
        {
            points[i].update();
            points[i].draw();
        }
        
        EndDrawing();
    }
    
}