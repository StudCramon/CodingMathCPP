#include "raylib.h"

void drawTile(int x, int y, Color color);
void drawBlock(int x, int y, int z);

int main()
{
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);

    RenderTexture2D target = LoadRenderTexture(width, height);
    BeginTextureMode(target);
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            if(GetRandomValue(0, 100) > 90)
            {
                drawBlock(i, j, 1);
            }
            drawTile(i, j, SKYBLUE);
        }
    }
    EndTextureMode();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawTexture(target.texture, 0, 0, WHITE);

        EndDrawing();
    }
    
}

void drawTile(int x, int y, Color color)
{
    static float screenWidth = GetScreenWidth();
    static Vector2 zero{screenWidth/2, 50};
    static const int tileWidth = 100;
    static const int tileHeight = 50;

    Vector2 point;
    point.x = zero.x + (x - y)*tileWidth/2;
    point.y = zero.y + (x + y)*tileHeight/2;


    DrawLine(point.x, point.y, point.x + tileWidth/2, point.y + tileHeight/2, color);
    DrawLine(point.x + tileWidth/2, point.y + tileHeight/2, point.x, point.y + tileHeight, color);
    DrawLine(point.x, point.y + tileHeight, point.x - tileWidth/2, point.y + tileHeight/2, color);
    DrawLine(point.x - tileWidth/2, point.y + tileHeight/2, point.x, point.y, color);

    DrawEllipse(point.x, point.y + tileHeight/2, tileWidth/2.8, tileHeight/2.8, color);
    
}

void drawBlock(int x, int y, int z)
{
    Color color = GRAY;
    static float screenWidth = GetScreenWidth();
    static Vector2 zero{screenWidth/2, 50};
    static const int tileWidth = 100;
    static const int tileHeight = 50;

    Vector2 point;
    point.x = zero.x + (x - y)*tileWidth/2;
    point.y = (zero.y + (x + y)*tileHeight/2) - z * tileHeight;

    //top
    DrawLine(point.x, point.y, point.x + tileWidth/2, point.y + tileHeight/2, color);
    DrawLine(point.x + tileWidth/2, point.y + tileHeight/2, point.x, point.y + tileHeight, color);
    DrawLine(point.x, point.y + tileHeight, point.x - tileWidth/2, point.y + tileHeight/2, color);
    DrawLine(point.x - tileWidth/2, point.y + tileHeight/2, point.x, point.y, color);

    DrawEllipse(point.x, point.y + tileHeight/2, tileWidth/2.8, tileHeight/2.8, color);

    //left
    DrawLine(point.x, point.y + tileHeight, point.x, point.y + tileHeight + z * tileHeight, color);
    DrawLine(point.x - tileWidth/2, point.y + tileHeight/2, point.x - tileWidth/2, point.y + tileHeight/2 + z * tileHeight, color);
    DrawLine(point.x, point.y + tileHeight, point.x, point.y + tileHeight + z * tileHeight, color);
    DrawLine(point.x, point.y + tileHeight + z * tileHeight, point.x - tileWidth/2, point.y + tileHeight/2 + z * tileHeight, color);

    //right
    DrawLine(point.x + tileWidth/2, point.y + tileHeight/2, point.x + tileWidth/2, point.y + tileHeight/2 + z * tileHeight, color);
    DrawLine(point.x, point.y + tileHeight + z * tileHeight, point.x + tileWidth/2, point.y + tileHeight/2 + z * tileHeight, color);
}

void drawTileTexture(int x, int y, Color color)
{
    static float screenWidth = GetScreenWidth();
    static Vector2 zero{screenWidth/2, 50};
    static const int tileWidth = 100;
    static const int tileHeight = 50;

    Vector2 point;
    point.x = zero.x + (x - y)*tileWidth/2;
    point.y = zero.y + (x + y)*tileHeight/2;


    DrawLine(point.x, point.y, point.x + tileWidth/2, point.y + tileHeight/2, color);
    DrawLine(point.x + tileWidth/2, point.y + tileHeight/2, point.x, point.y + tileHeight, color);
    DrawLine(point.x, point.y + tileHeight, point.x - tileWidth/2, point.y + tileHeight/2, color);
    DrawLine(point.x - tileWidth/2, point.y + tileHeight/2, point.x, point.y, color);

    DrawEllipse(point.x, point.y + tileHeight/2, tileWidth/2.8, tileHeight/2.8, color);
    
}

void drawBlockTexture(int x, int y, int z)
{
    Color color = GRAY;
    static float screenWidth = GetScreenWidth();
    static Vector2 zero{screenWidth/2, 50};
    static const int tileWidth = 100;
    static const int tileHeight = 50;

    Vector2 point;
    point.x = zero.x + (x - y)*tileWidth/2;
    point.y = (zero.y + (x + y)*tileHeight/2) - z * tileHeight;

    //top
    DrawLine(point.x, point.y, point.x + tileWidth/2, point.y + tileHeight/2, color);
    DrawLine(point.x + tileWidth/2, point.y + tileHeight/2, point.x, point.y + tileHeight, color);
    DrawLine(point.x, point.y + tileHeight, point.x - tileWidth/2, point.y + tileHeight/2, color);
    DrawLine(point.x - tileWidth/2, point.y + tileHeight/2, point.x, point.y, color);

    DrawEllipse(point.x, point.y + tileHeight/2, tileWidth/2.8, tileHeight/2.8, color);

    //left
    DrawLine(point.x, point.y + tileHeight, point.x, point.y + tileHeight + z * tileHeight, color);
    DrawLine(point.x - tileWidth/2, point.y + tileHeight/2, point.x - tileWidth/2, point.y + tileHeight/2 + z * tileHeight, color);
    DrawLine(point.x, point.y + tileHeight, point.x, point.y + tileHeight + z * tileHeight, color);
    DrawLine(point.x, point.y + tileHeight + z * tileHeight, point.x - tileWidth/2, point.y + tileHeight/2 + z * tileHeight, color);

    //right
    DrawLine(point.x + tileWidth/2, point.y + tileHeight/2, point.x + tileWidth/2, point.y + tileHeight/2 + z * tileHeight, color);
    DrawLine(point.x, point.y + tileHeight + z * tileHeight, point.x + tileWidth/2, point.y + tileHeight/2 + z * tileHeight, color);
}