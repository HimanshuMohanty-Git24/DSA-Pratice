/*Q1) Write and execute a C++ program which create a shape class and derive circle and square class from shape class.
Define appropriate constructor for all the three classes. Define Find-Area method in shape class and override this
method in circle and square classes to find their area.*/
#include <iostream>
using namespace std;
class shape
{
public:
    virtual void area() = 0;
};

class circle : public shape
{
    float r;

public:
    circle(float radius)
    {
        r = radius;
    }
    void area()
    {
        cout << "\nArea of circle : " << (3.14 * r * r);
    }
};

class square : public shape
{
    int side;

public:
    square(float s)
    {
        side = s;
    }
    void area()
    {
        cout << "\nArea of square : " << side * side;
    }
};

int main()
{
    shape *s;

    circle c(4);
    s = &c;
    s->area();

    square t(5);
    s = &t;
    s->area();

    return 0;
}