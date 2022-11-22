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