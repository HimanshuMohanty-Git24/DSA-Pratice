#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int nCr(int n, int r)
{
    int numerartor = factorial(n);
    int denominator = factorial(r) * factorial(n - r);
    int ans = numerartor / denominator;
    return ans;
}
int main()
{
    int ans = nCr(8, 2);
    cout << "nCr:" << ans;
    return 0;
}