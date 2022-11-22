/*Q4) Write a C++ program to define Shape class. Derive Circle and Triangle classes from the Shape class.
 Define method area in Shape class and override it in classes Circle and Triangle to calculate their area.
 Make necessary assumptions required.*/
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