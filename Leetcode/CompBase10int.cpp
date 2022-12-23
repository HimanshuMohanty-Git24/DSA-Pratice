#include <bits/stdc++.h>
using namespace std;
int bitwiseComplement(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int m = n;
    int mask = 0;
    while (m != 0)
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~n) & mask;
    return ans;
}
int main()
{
    int ans = bitwiseComplement(7);
    cout << ans;
    return 0;
}