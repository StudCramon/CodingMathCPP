#include "MyUtility.h"

float Util::getRand1f()
{
    float number = (rand()%1000 + 1) * 0.001;
    return number;
}

float Util::norm(float value, float min, float max)
{
    return (value - min)/(value - max);
}

float Util::lerp(float norm, float min, float max)
{
    return (max - min) * norm + min;
}

float Util::map(float value, float sourceMin, float sourceMax, float destMin, float destMax)
{
    float n = norm(value, sourceMin, sourceMax);
    return lerp(n, destMin, destMax);
}

float Util::clamp(float value, float min, float max)
{
    float val = std::fmax(value, fmin(min, max));
    return std::fmin(val, fmax(min, max));
}

float Util::distance(const MyVector& v1, const MyVector& v2)
{
    float dx = v1.x - v2.x;
    float dy = v1.y - v2.y;
    return sqrt(dx * dx + dy * dy);
}

bool Util::circleCollision(const MyParticle& c1, const MyParticle& c2)
{
    return distance(MyVector(c1.x, c1.y), MyVector(c2.x, c2.y)) <= c1.radius + c2.radius;
}

bool Util::circlePointCollision(const MyParticle& c1, const MyVector& p1)
{
    return distance(MyVector(c1.x, c1.y), p1) < c1.radius;
}

bool Util::pointInRect(const MyVector& p1, const MyVector& r1, float width, float height)
{
    return inRange(p1.x, r1.x, r1.x + width) && 
           inRange(p1.y, r1.y, r1.y + height);
}
    
bool Util::inRange(float value, float min, float max)
{
    return value >= fmin(min, max) && value <= fmax(min, max);
}

bool Util::rangeIntersect(float min0, float max0, float min1, float max1)
{
    return fmax(min0, max0) >= fmin(min1, max1) && 
           fmin(min0, max0) <= fmax(min1, max1);
}

bool Util::rectIntersect(const MyVector& r1, float width1, float height1, const MyVector& r2, float width2, float height2)
{
    return rangeIntersect(r1.x, r1.x + width1, r2.x, r2.x + width2) &&
           rangeIntersect(r1.y, r1.y + height1, r2.y, r2.y + height2);
           
}

float Util::degreesToRads(float degrees)
{
    return degrees / (180 * 3.1415926535f);
}

float Util::radsToDegrees(float radians)
{
    return (radians * 180) / 3.1415926535f;
}

float Util::roundToPlaces(float value, float places)
{
    int mult = pow(10, places);
    return round(value * mult) / mult;
}

float Util::roundToNearest(float value, float nearest)
{
    return round(value / nearest) * nearest;
}

void Util::quadraticBezier(MyVector& p0, MyVector& p1, MyVector& p2, float t, MyVector& Outp)
{
    Outp.x = pow(1 - t, 2) * p0.x +
                (1 - t) * 2 * t * p1.x +
                t * t * p2.x;
    Outp.y = pow(1 - t, 2) * p0.y + 
                (1 - t) * 2 * t * p1.y +
                t * t * p2.y;
}

void Util::cubicBezier(const MyVector& p0, const MyVector& p1, const MyVector& p2, const MyVector& p3, float t, MyVector& pOut)
{
    pOut.x = pow(1 - t, 3) * p0.x +
             pow(1 - t, 2) * 3 * t * p1.x +
             (1 - t) * 3 * t * t * p2.x +
             t * t * t * p3.x;
    pOut.y = pow(1 - t, 3) * p0.y +
             pow(1 - t, 2) * 3 * t * p1.y + 
             (1 - t) * 3 * t * t * p2.y +
             t * t * t * p3.y;
}

void Util::multiBezier(const std::vector<MyVector>& points, float gT, MyVector& pOut) 
{
    int CPCount = points.size() - 2;
    float norm = CPCount * gT;
    int startPoint = norm;
    if(startPoint == CPCount)
        --startPoint;

    if(startPoint == 0)
    {
        MyVector p0(points[startPoint]);
        MyVector p1(points[startPoint + 1]);
        MyVector p2((points[startPoint + 2].x + p1.x)/2, (points[startPoint + 2].y + p1.y)/2);
        quadraticBezier(p0, p1, p2, norm, pOut);
        return;
    }
    else if(startPoint == CPCount - 1)
    {
        MyVector p1(points[startPoint + 1]);
        MyVector p2(points[startPoint + 2]);
        MyVector p0((points[startPoint].x + p1.x)/2, (points[startPoint].y + p1.y)/2);
        float t = norm - startPoint;
        quadraticBezier(p0, p1, p2, t, pOut);
        return;
    }

    MyVector p1(points[startPoint + 1]);
    MyVector p0((points[startPoint].x + p1.x)/2, (points[startPoint].y + p1.y)/2);
    MyVector p2((points[startPoint + 2].x + p1.x)/2, (points[startPoint + 2].y + p1.y)/2);
    float t = norm - startPoint;
    quadraticBezier(p0, p1, p2, t, pOut);

}