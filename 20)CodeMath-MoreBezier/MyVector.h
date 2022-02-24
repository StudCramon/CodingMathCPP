#ifndef MYVECTOR
#define MYVECTOR

class MyVector
{
public:
    float x;
    float y;

    MyVector(float x1, float y1) : x{x1}, y{y1} {}

    MyVector() : x{0}, y{0} {}

    ~MyVector() {}

    virtual float getLenght() const final;

    virtual float getAngle() const final;

    virtual void setLenght(float newLenght) final;

    virtual void setAngle(float newAngle) final;

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