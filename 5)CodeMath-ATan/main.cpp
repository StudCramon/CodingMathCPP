#include "raylib.h"
#include <cstdio>
#include <math.h>

void DrawMyTexture(Texture&);

int main()
{
    int width = 800;
    int height = 600;
    InitWindow(width, height, "Canvas");

    Vector2 center{float(width/2), float(height/2)};
    int arrowLenght = 50;
    Vector2 arrowOrig{center.x - arrowLenght/2, center.y};
    Vector2 arrowEnd{center.x + arrowLenght/2, center.y};
    int dx, dy;
    float angle = 0.0f;
    float speed = 0.5;

    RenderTexture2D target = LoadRenderTexture(width, height);
    BeginTextureMode(target);

    DrawLine(arrowOrig.x, arrowOrig.y, arrowEnd.x, arrowEnd.y, RED);
    DrawLine(arrowEnd.x, arrowEnd.y, arrowEnd.x - 20, arrowEnd.y + 10, RED);
    DrawLine(arrowEnd.x, arrowEnd.y, arrowEnd.x - 20, arrowEnd.y - 10, RED);


    EndTextureMode();

    Rectangle ArrowSrc{0, 0, float(width), float(height)};
    Rectangle ArrowDest{float(width/2), float(height/2), float(width), float(height)};
    Vector2 ArrowOrigin{float(target.texture.width/2), float(target.texture.height/2)};
    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Vector2 mousePos = GetMousePosition();
        dx = mousePos.x - ArrowDest.x;
        dy = mousePos.y - ArrowDest.y;
        angle = atan2(dy, dx);
        //-----------------------------Drawing with trace----------------------------------------
        BeginTextureMode(target);
        //code here
        //code end
        EndTextureMode();
        //------------------------------Drawing with trace END----------------------------------------
        DrawTexturePro(target.texture, 
                        ArrowSrc,
                        ArrowDest,
                        ArrowOrigin,
                        (angle*180)/PI, 
                        WHITE);
        char array[3];
        sprintf(array, "%f", angle);
        DrawText(array, 0, 0, 20, RED);

        if(IsKeyDown(KEY_W) && ArrowDest.y > 0)
        {
            ArrowDest.y -= speed;
        }

        if(IsKeyDown(KEY_S) && ArrowDest.y < height)
        {
            ArrowDest.y += speed;
        }

        if(IsKeyDown(KEY_D) && ArrowDest.x < width)
        {
            ArrowDest.x += speed;
        }

        if(IsKeyDown(KEY_A) && ArrowDest.x > 0)
        {
            ArrowDest.x -= speed;
        }

        EndDrawing();
    }
    

    return 0;
}