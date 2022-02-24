#include "raylib.h"
#include <math.h>


void sierpinsci(const Vector2& p0, const Vector2& p1, const Vector2& p2, int limit);
void koch(const Vector2& p0, const Vector2& p1, int limit);

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    Vector2 center{width/2, height/2};

    Vector2 p0{0 + center.x, -321 + center.y};
    Vector2 p1{278 + center.x, 160 + center.y};
    Vector2 p2{-278 + center.x, 160 + center.y};

    int limit = 0;
    float iter = 0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        //DrawTriangle(p2, p1, p0, BLACK);
        limit = 8 * sin(iter);
        iter += 0.05;
            koch(p1, p2, limit);
            koch(p2, p0, limit);
            koch(p0, p1, limit);
        EndDrawing();
    }
    
}

void sierpinsci(const Vector2& p0, const Vector2& p1, const Vector2& p2, int limit)
{
    if(limit > 0)
    {
        Vector2 pA{(p0.x + p1.x)/2, (p0.y + p1.y)/2};
        Vector2 pB{(p1.x + p2.x)/2, (p1.y + p2.y)/2};
        Vector2 pC{(p0.x + p2.x)/2, (p0.y + p2.y)/2};

        sierpinsci(p0, pA, pC, limit - 1);
        sierpinsci(pA, p1, pB, limit - 1);
        sierpinsci(pC, pB, p2, limit - 1);
    }
    else
    {
        DrawTriangle(p0, p1, p2, BLACK);
    }
}

void koch(const Vector2& p0, const Vector2& p1, int limit)
{
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;

    float angle = atan2(dy, dx);
    float unit = sqrt(dx*dx + dy*dy) / 3;

    Vector2 pA{
        p0.x + dx/3,
        p0.y + dy/3
    };
    Vector2 pC{
        p1.x - dx/3,
        p1.y - dy/3
    };
    Vector2 pB{
        pA.x + unit * cos(angle - PI/3),
        pA.y + unit * sin(angle - PI/3)
    };

    if(limit > 0)
    {
        koch(p0, pA, limit - 1);
        koch(pA, pB, limit - 1);
        koch(pB, pC, limit - 1);
        koch(pC, p1, limit - 1);
    }
    else
    {
        DrawLine(p0.x, p0.y, pA.x, pA.y, BLACK);
        DrawLine(pA.x, pA.y, pB.x, pB.y, BLACK);
        DrawLine(pB.x, pB.y, pC.x, pC.y, BLACK);
        DrawLine(pC.x, pC.y, p1.x, p1.y, BLACK);
    }
}