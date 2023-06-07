#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "\nEnter the value of n\n";
    int n;
    cin >> n;
    cout << "\nn=" << n << endl;
    cout << "\nPattern 1:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
    cout << "\nPattern 2:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << n - j << " ";
        }
        cout << endl;
    }
    cout << "\nPattern 3:\n";
    static int ctr = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ctr++ << " ";
        }
        cout << endl;
    }
     return 0;
}