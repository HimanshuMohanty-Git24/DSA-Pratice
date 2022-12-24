#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n100 = 0, n50 = 0, n20 = 0, n01 = 0;
    int amount = 5555;
    switch (amount >= 100)
    {
    case 1:
        n100 = amount / 100;
        amount -= n100 * 100;
        break;
    }
    switch (amount >= 50)
    {
    case 1:
        n50 = amount / 50;
        amount -= n50 * 50;
    }
    switch (amount >= 20)
    {
    case 1:
        n20 = amount / 20;
        amount -= n20 * 20;
        break;
    }
    switch (amount >= 1)
    {
    case 1:
        n01 = amount / 10;
        amount -= n01 * 10;
        break;
    }
    cout << "100 RS notes:" << n100 << endl;
    cout << "50 RS notes:" << n50 << endl;
    cout << "20 RS notes:" << n20 << endl;
    cout << "1 RS notes:" << n01 << endl;

    return 0;
}