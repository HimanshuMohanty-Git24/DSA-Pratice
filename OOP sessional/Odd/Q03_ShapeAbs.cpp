/*Q3) Write a C++ program to create an abstract class shape with method area( ).
Derive Circle and Triangle classes from Shape class. Override method area( ) in
the derived classes to find the area of respective shapes. Also define appropriate
constructors in your program.Make necessary assumptions required.*/
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

class triangle : public shape
{
    int side, height;

public:
    triangle(float s, float h)
    {
        side = s;
        height = h;
    }
    void area()
    {
        cout << "\nArea of triangle : " << 0.5 * side * height;
    }
};

int main()
{
    shape *s;

    circle c(4);
    s = &c;
    s->area();

    triangle t(3, 5);
    s = &t;
    s->area();

    return 0;
}