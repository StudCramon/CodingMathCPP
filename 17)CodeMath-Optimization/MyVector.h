#ifndef MYVECTOR
#define MYVECTOR

class MyVector
{
private:
    float x;
    float y;
public:

    MyVector(float x1, float y1) : x{x1}, y{y1} {}

    MyVector() : x{0}, y{0} {}

    ~MyVector() {}

    float getX() const {return this->x;}

    float getY() const {return this->y;}

    void setX(float num) {x = num;}

    void setY(float num) {y = num;}

    float getLenght() const;

    float getAngle() const;

    void setLenght(float newLenght);

    void setAngle(float newAngle);

    friend MyVector operator+(const MyVector& v1, const MyVector& v2);

    friend MyVector operator-(const MyVector& v1, const MyVector& v2);

    friend MyVector operator*(const MyVector& v1, float val);

    friend MyVector operator/(const MyVector& v1, float val);

    MyVector operator+=(const MyVector& v1);

    MyVector operator-=(const MyVector& v1);

    MyVector operator*=(float num);

    MyVector operator/=(float num);
};

#endif