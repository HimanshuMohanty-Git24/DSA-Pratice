// Q1)Write a C++ program to overload `+' operator, to find S1 + S2, where S1 and S2 are two strings.
//(Hint `+' to be used to concatenate two strings)
#include <iostream>
#include <string>
using namespace std;
class str
{
private:
    string text;

public:
    str(string txt)
    {
        text = txt;
    }
    friend string operator+(str s1, str s2);
    void display()
    {
        cout << text << endl;
    }
};
string operator+(str s1, str s2)
{
    string add;
    add = s1.text + " " + s2.text;
    return add;
}
int main()
{
    string txt1;
    cout << "Enter the first string:";
    cin >> txt1;
    str s1(txt1);
    string txt2;
    cout << "Enter the Second string:";
    cin >> txt2;
    str s2(txt2);
    str s3 = s1 + s2;
    s3.display();
}