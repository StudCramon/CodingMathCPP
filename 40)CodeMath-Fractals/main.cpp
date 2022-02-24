#include "raylib.h"
#include <math.h>

void tree(Vector2 p0, Vector2 p1, float branchAngle, float trunkRatio, int limit);
void pyTree(Rectangle rec, int limit, float branchRotation, float rootRotation = -90);
Vector2 findRecLowerPoint(Rectangle rec, float rotation);
Vector2 findRecSidePoint(Rectangle rec, float rotation);

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);

    float angle = 0;

    Rectangle rect{width/2 - 50, height, 100, 100};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        angle += 0.1;

        pyTree(rect, 12, angle);

        EndDrawing();
    }
    
}

void tree(Vector2 p0, Vector2 p1, float branchAngle, float trunkRatio, int limit)
{
    float dx = p1.x - p0.x;
    float dy = p1.y - p0.y;
    float distance = sqrt(dx*dx + dy*dy);
    float angle = atan2(dy, dx);
    float branchLenght = distance * (1 - trunkRatio);
    Vector2 pA{p0.x + dx * trunkRatio, p0.y + dy * trunkRatio};
    Vector2 pB{pA.x + branchLenght * cos(angle + branchAngle), pA.y + branchLenght * sin(angle + branchAngle)};
    Vector2 pC{pA.x + branchLenght * cos(angle - branchAngle), pA.y + branchLenght * sin(angle - branchAngle)};

    DrawLineV(p0, pA, BLACK);

    if(limit <= 0)
    {
        DrawLineV(pA, pB, BLACK);
        DrawLineV(pA, pC, BLACK);
    }
    else
    {
        tree(pA, pB, branchAngle, trunkRatio, limit - 1);
        tree(pA, pC, branchAngle, trunkRatio, limit - 1);
    }

}

void pyTree(Rectangle rec, int limit, float branchRotation, float rootRotation)
{
    if(rec.width != rec.height)
    {
        return;
    }

    DrawRectanglePro(rec, Vector2{0,0}, rootRotation, BLACK);

    Vector2 leftBranchOrigin = findRecSidePoint(rec, rootRotation);
    float leftBranchAngle = - branchRotation + rootRotation;
    float leftBranchWidth = cos(branchRotation*DEG2RAD) * rec.width;
    Rectangle leftBranch{leftBranchOrigin.x, leftBranchOrigin.y, leftBranchWidth, leftBranchWidth};

    Vector2 rightBranchOrigin = findRecLowerPoint(leftBranch, leftBranchAngle);
    float rightBranchAngle = leftBranchAngle + 90;
    float rightBranchWidth = sin((branchRotation)*DEG2RAD) * rec.width;
    Rectangle rightBranch{rightBranchOrigin.x, rightBranchOrigin.y, rightBranchWidth, rightBranchWidth};
    
    DrawRectanglePro(leftBranch, Vector2{0, 0}, leftBranchAngle, BLACK);
    DrawRectanglePro(rightBranch, Vector2{0, 0}, rightBranchAngle, BLACK);

    if(limit <= 0)
    {
        return;
    }
    else
    {
        pyTree(leftBranch, limit - 1, branchRotation, leftBranchAngle);
        pyTree(rightBranch, limit - 1, branchRotation, rightBranchAngle);
    }


}

Vector2 findRecLowerPoint(Rectangle rec, float rotation)
{
    Vector2 answer;
    answer.x = rec.x + cos((rotation + 90)*DEG2RAD) * rec.height;
    answer.y = rec.y + sin((rotation + 90)*DEG2RAD) * rec.height;
    return answer;
}

Vector2 findRecSidePoint(Rectangle rec, float rotation)
{
    Vector2 answer;
    answer.x = rec.x + cos((rotation)*DEG2RAD)*rec.height;
    answer.y = rec.y + sin((rotation)*DEG2RAD)*rec.width;
    return answer;
}