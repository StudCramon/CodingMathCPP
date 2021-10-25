#include <iostream>
#include <ctime>
using namespace std;

float getRand1f();

int main()
{
    cout << getRand1f();
}

float getRand1f()
{
    srand(static_cast<unsigned int>(time(0)));
    float number = (rand()%1000 + 1) * 0.001;
    return number;
}