/*Q1) Write and execute a C++ program which create a shape class and derive circle and square class from shape class.
Define appropriate constructor for all the three classes. Define Find-Area method in shape class and override this
method in circle and square classes to find their area.*/
#include <iostream>
using namespace std;
class shape
{
public:
    virtual void area()
    {
        cout << "This is a virtual class";
    }
};
class circle : public shape
{
    float r;

public:
    void area()
    {
        cout << "\nEnter radius : ";
        cin >> r;
        cout << "\nArea of circle : " << (3.141 * r * r);
    }
};
class triangle : public shape
{

    int h, b;
    float a;

public:
    void area()
    {
        cout << "\nEnter height : ";
        cin >> h;
        cout << "\nEnter breadth : ";
        cin >> b;
        a = 0.5 * h * b;
        cout << "\nArea of triangle : " << a;
    }
};
int main()
{
    circle c;
    c.area();
    triangle t;
    t.area();
    return 0;
}