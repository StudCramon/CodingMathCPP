#include "MyVector.h"
#include "math.h"

float MyVector::getLenght() const
{
    return sqrt(x*x + y*y);
}

float MyVector::getAngle() const
{
    return atan2(y, x);
}

void MyVector::setLenght(float newLenght)
{
    float angle = getAngle();
    x = cos(angle) * newLenght;
    y = sin(angle) * newLenght;
}

void MyVector::setAngle(float newAngle)
{
    float lenght = getLenght();
    x = cos(newAngle) * lenght;
    y = sin(newAngle) * lenght;
}

MyVector operator+(const MyVector& v1, const MyVector& v2)
{
    return MyVector(v1.x + v2.x, v1.y + v2.y);
}

MyVector operator-(const MyVector& v1, const MyVector& v2)
{
    return MyVector(v1.x - v2.x, v1.y - v2.y);
}

MyVector operator*(const MyVector& v1, float val)
{
    return MyVector(v1.x * val, v1.y * val);
}

MyVector operator/(const MyVector& v1, float val)
{
    return MyVector(v1.x/val, v1.y/val);
}

MyVector MyVector::operator+=(const MyVector& v1)
{
    this->x = this->x + v1.x; 
    this->y = this->y + v1.y;
    return *this;
}

MyVector MyVector::operator-=(const MyVector& v1)
{
    this->x = this->x - v1.x; 
    this->y = this->y - v1.y;
    return *this;
}

MyVector MyVector::operator*=(float num)
{
    this->x = this->x * num; 
    this->y = this->y * num;
    return *this;
}

MyVector MyVector::operator/=(float num)
{
    this->x = this->x / num; 
    this->y = this->y / num;
    return *this;
}