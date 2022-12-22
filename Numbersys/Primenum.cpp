#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 2;
    for (; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "Not Prime";
            return 0;
        }
    }
    printf("Yes Prime");

    return 0;
}