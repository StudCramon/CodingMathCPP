#include "raylib.h"
#include <vector>
#include "PhysicsEntity.h"
#include "PhysStick.h"

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    std::vector<PhysEnt> points;
    points.push_back(PhysEnt(100, 100, 95, 95));
    points.push_back(PhysEnt(200, 100, 200, 100));
    points.push_back(PhysEnt(200, 200, 200, 200));
    points.push_back(PhysEnt(100, 200, 100, 200));

    points.push_back(PhysEnt(550, 100, 550, 100));
    points[4].isStatic = true;
    points.push_back(PhysEnt(400, 100, 400, 100));
    points.push_back(PhysEnt(250, 100, 250, 100));


    std::vector<Stick> sticks;
    sticks.push_back(Stick(&points[0], &points[1]));
    sticks.push_back(Stick(&points[1], &points[2]));
    sticks.push_back(Stick(&points[2], &points[3]));
    sticks.push_back(Stick(&points[3], &points[0]));
    sticks.push_back(Stick(&points[0], &points[2]));
    sticks[4].stickColor = BLACK;
    sticks.push_back(Stick(&points[1], &points[3]));

    sticks.push_back(Stick(&points[4], &points[5]));
    sticks.push_back(Stick(&points[5], &points[6]));
    sticks.push_back(Stick(&points[6], &points[1]));
    //sticks.push_back(Stick(&points[7], &points[1]));

    size_t pointsSize = points.size();
    size_t sticksSize = sticks.size();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for(size_t i = 0; i < pointsSize; ++i)
        {
            points[i].update();
        }

        for(size_t i = 0; i < sticksSize; ++i)
        {
            sticks[i].update(10);
        }

        for(size_t i = 0; i < sticksSize; ++i)
        {
            sticks[i].draw();
        }

        // for(size_t i = 0; i < points.size(); ++i)
        // {
        //     points[i].draw();
        // }


        
        EndDrawing();
    }
    
}