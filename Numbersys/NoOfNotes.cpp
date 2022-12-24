#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n100 = 0, n50 = 0, n20 = 0, n01 = 0;
    int amount = 5555;
    switch (1)
    {
    case 1:
        n100 = amount / 100;
        amount = amount - (n100 * 100);
    case 2:
        n50 = amount / 50;
        amount = amount - (n50 * 50);
    case 3:
        n20 = amount / 20;
        amount = amount - (n20 * 20);
    case 4:
        n01 = amount / 1;
        amount = amount - (n01 * 1);
    default:
        break;
    }
    cout << "No. of 100 RS notes-->" << n100 << endl;
    cout << "No. of 50 RS notes-->" << n50 << endl;
    cout << "No. of 20 RS notes-->" << n20 << endl;
    cout << "No. of 1 RS notes-->" << n01 << endl;
    return 0;
}