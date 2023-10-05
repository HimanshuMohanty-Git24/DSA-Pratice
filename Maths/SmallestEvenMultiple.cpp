// 2413. Smallest Even Multiple
#include <bits/stdc++.h>
using namespace std;
int smallestEvenMultiple(int n)
{
    for (int i = 2; i <= n * 2; i++)
    {
        if (i % 2 == 0 && i % n == 0)
        {
            return i;
        }
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    int res = smallestEvenMultiple(n);
    cout << res << endl;
    return 0;
}