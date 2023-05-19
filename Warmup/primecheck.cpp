#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count > 0)
    {
        cout << "Not Prime";
    }
    else
    {
        cout << "Prime";
    }

    return 0;
}