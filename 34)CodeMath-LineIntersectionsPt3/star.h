#ifndef __STAR_H__
#define __STAR_H__

#include "raylib.h"
#include <array>

class Star
{
public:
    Vector2 pos;
    std::array<Vector2, 10> corners;
    const std::array<Vector2, 10> offsets = {
        Vector2{100, 0},
        Vector2{40, 29},
        Vector2{31, 95},
        Vector2{-15, 48},
        Vector2{-81, 59},
        Vector2{-50, 0},
        Vector2{-81, -59},
        Vector2{-15, -48},
        Vector2{31, -95},
        Vector2{40, -29}
    };
    
    Star(float x = 0, float y = 0): pos{x, y}
    {
        for(int i = 0; i < corners.size(); ++i)
        {
            corners[i].x = pos.x + offsets[i].x;
            corners[i].y = pos.y + offsets[i].y;
        }
    }

    void draw();
    void update();
    bool isCollidingWith(const Star& star);
};

bool lineIntersect(const Vector2& p11, const Vector2& p12, const Vector2& p21, const Vector2& p22, Vector2& outPoint);
bool SectionIntersect(const Vector2& p11, const Vector2& p12, const Vector2& p21, const Vector2& p22, Vector2& outPoint);
bool linePointIntersection(const Vector2& point, const Vector2& lineStart, const Vector2& lineEnd);

#endif // __STAR_H__