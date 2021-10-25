#include "raylib.h"
#include <math.h>
#include "MyVector.h"
#include "MyParticle.h"

void DrawMyTriangle(RenderTexture2D&, float, float, float, float);

int main()
{
    MyVector a;
    int width = 1280;
    int height = 720;
    InitWindow(width, height, "Canvas");
    SetTargetFPS(60);
    MyParticle ship(width/2, height/2, 0, 0);
    MyVector thrust;
    float angle = 0;
    bool turningLeft = false;
    bool turningRight = false;
    bool thrusting = false;

    RenderTexture2D target = LoadRenderTexture(width, height);
    DrawMyTriangle(target, width/2, height/2, 20, 30);

    Rectangle TriSrc{0, 0, float(width), float (height)};
    Vector2 TriOrigin{float(target.texture.width/2), float(target.texture.height/2)};
    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Rectangle TriDest{ship.GetPosition().getX(), ship.GetPosition().getY(), float(width), float(height)};

        ship.Accelerate(thrust);
        ship.Move();
        DrawTexturePro(
            target.texture,
            TriSrc,
            TriDest,
            TriOrigin,
            ((angle-PI/2)*180)/PI,
            WHITE
        );

        if(turningLeft)
        {
            angle -= 0.05;
        }
        if(turningRight)
        {
            angle += 0.05;
        }

        thrust.setAngle(angle);

        if(thrusting)
        {
            thrust.setLenght(0.1);
        }
        else
        {
            thrust.setLenght(0);
        }

        if(IsKeyPressed(KEY_W))
        {
            thrusting = true;
        }
        if(IsKeyPressed(KEY_A))
        {
            turningLeft = true;
        }
        if(IsKeyPressed(KEY_D))
        {
            turningRight = true;
        }
        
        if(IsKeyUp(KEY_W))
        {
            thrusting = false;
        }
        if(IsKeyUp(KEY_A))
        {
            turningLeft = false;
        }
        if(IsKeyUp(KEY_D))
        {
            turningRight = false;
        }

        if(ship.GetPosition().getX() > width)
        {
            ship.SetX(0);
        }
        else if(ship.GetPosition().getX() < 0)
        {
            ship.SetX(width);
        }

        if(ship.GetPosition().getY() > height)
        {
            ship.SetY(0);
        }
        else if(ship.GetPosition().getY() < 0)
        {
            ship.SetY(height);
        }

        EndDrawing();
    }
    
    
    return 0;
}

void DrawMyTriangle(RenderTexture2D& target, float centerX, float centerY, float width, float height)
{
    BeginTextureMode(target);
	
	DrawLine(centerX, centerY - height/2, centerX - width/2, centerY + height/2, BLACK);
    DrawLine(centerX - width/2, centerY + height/2, centerX + width/2, centerY + height/2, BLACK);
    DrawLine(centerX + width/2, centerY + height/2, centerX, centerY - height/2, BLACK);

    EndTextureMode();
}