// Q2)Write a C++ program to find a + b, a — b, a * b and a/ b, where a and b are two numbers.
//  Implement proper mechanism to handle exception(s) in this program
#include <iostream>
#include <exception>
#include <stdlib.h>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    int choice;
    cout << "Press 1 for Addition" << endl;
    cout << "Press 2 for Substraction" << endl;
    cout << "Press 3 for Multiplication" << endl;
    cout << "Press 4 for Division" << endl;
    cout << "Press 0 to exit" << endl;
    while (1)
    {
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(1);
            break;
        case 1:
            int add;
            add = a + b;
            cout << "Addition:" << add << endl;
            break;
        case 2:
            int sub;
            sub = a - b;
            cout << "Substraction:" << sub << endl;
            break;
        case 3:
            int mul;
            mul = a * b;
            cout << "Multiplication:" << mul << endl;
            break;
        case 4:
            int divide;
            try
            {
                if (b == 0)
                    throw "Divided by zero";
                float div = (float)a / (float)b;
                cout << "Division:" << div << endl;
            }
            catch (const char *e)
            {
                cout << "Exception occured" << endl
                     << e << endl;
            }
            break;
        default:
            break;
        }
    }
}