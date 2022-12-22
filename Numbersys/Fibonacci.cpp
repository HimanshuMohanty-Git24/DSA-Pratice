#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";
    for (int i = 1; i <= n; i++)
    {
        int nextNum = a + b; // n=(n-1)+(n-2) Fibonacci
        cout << nextNum << " ";
        a = b;
        b = nextNum;
    }

    return 0;
}