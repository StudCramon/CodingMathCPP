#include "star.h"

void Star::draw()
{
    for(int i = 1; i < corners.size(); ++i)
    {
        DrawLine(corners[i-1].x, corners[i-1].y, corners[i].x, corners[i].y, BLACK);
    }
    DrawLine(corners[0].x, corners[0].y, corners[corners.size() - 1].x, corners[corners.size() - 1].y, BLACK);
}

void Star::update()
{
    for(int i = 0; i < corners.size(); ++i)
        {
            corners[i].x = pos.x + offsets[i].x;
            corners[i].y = pos.y + offsets[i].y;
        }
}

bool Star::isCollidingWith(const Star& star)
{
    bool isColliding = false;
    Vector2 collidingPoint;
    for(int i = 0; i < corners.size(); ++i)
    {
        Vector2 p0 = corners[i];
        Vector2 p1 = corners[(i+1) % corners.size()];
        for(int j = 0; j < star.corners.size(); ++j)
        {
            Vector2 p2 = star.corners[j];
            Vector2 p3 = star.corners[(j+1) % star.corners.size()];
            if(SectionIntersect(p0, p1, p2, p3, collidingPoint))
            {
                isColliding = true;
                DrawCircle(collidingPoint.x, collidingPoint.y, 5, RED);
            }
        }
    }
    return isColliding;
}


bool lineIntersect(const Vector2& p11, const Vector2& p12, const Vector2& p21, const Vector2& p22, Vector2& outPoint)
{
    float A1 = p12.y - p11.y;
    float B1 = p11.x - p12.x;
    float C1 = A1 * p11.x + B1 * p11.y;

    float A2 = p22.y - p21.y;
    float B2 = p21.x - p22.x;
    float C2 = A2 * p21.x + B2 * p21.y;

    float denominator = A1 * B2 - A2 * B1;

    if(denominator == 0)
    {
        if(C1 == C2)
        {
            //std::cout << "Lines are equal" << std::endl;
            return false;
        }
        else
        {
            //std::cout << "Lines are parallel" << std::endl;
            return false;
        }

    }

    outPoint.x = (B2 * C1 - B1 * C2) / denominator;
    outPoint.y = (A1 * C2 - A2 * C1) / denominator;
    return true;
}

bool SectionIntersect(const Vector2& p11, const Vector2& p12, const Vector2& p21, const Vector2& p22, Vector2& outPoint)
{
    float A1 = p12.y - p11.y;
    float B1 = p11.x - p12.x;
    float C1 = A1 * p11.x + B1 * p11.y;

    float A2 = p22.y - p21.y;
    float B2 = p21.x - p22.x;
    float C2 = A2 * p21.x + B2 * p21.y;

    float denominator = A1 * B2 - A2 * B1;

    if(denominator == 0)
    {
        if(C1 == C2)
        {
            //std::cout << "Lines are equal" << std::endl;
            return false;
        }
        else
        {
            //std::cout << "Lines are parallel" << std::endl;
            return false;
        }

    }

    Vector2 tempPoint;
    tempPoint.x = (B2 * C1 - B1 * C2) / denominator;
    tempPoint.y = (A1 * C2 - A2 * C1) / denominator;
    
    if(linePointIntersection(tempPoint, p11, p12) && linePointIntersection(tempPoint, p21, p22))
    {
        outPoint = tempPoint;
        return true;
    }
    else
    {
        outPoint.x = 0;
        outPoint.y = 0;
        return false;
    }

}

bool linePointIntersection(const Vector2& point, const Vector2& lineStart, const Vector2& lineEnd)
{
    float lineLenghtX = lineEnd.x - lineStart.x;
    float lineLenghtY = lineEnd.y - lineStart.y;

    float pointToStartLenghtX = point.x - lineStart.x;
    float pointToStartLenghtY = point.y - lineStart.y;

    float interX = pointToStartLenghtX/lineLenghtX;
    float interY = pointToStartLenghtY/lineLenghtY;

    if(interX >= 0 && interY <=1 && interY >= 0 && interY <=1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}