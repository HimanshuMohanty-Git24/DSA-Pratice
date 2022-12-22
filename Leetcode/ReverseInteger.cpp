/*7. Reverse Integer*/
#include <bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    int r, rev = 0;
    while (x != 0)
    {
        r = x % 10;
        if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10))
        {
            return 0;
        }
        x = x / 10;
        rev = rev * 10 + r;
    }
    if (sizeof(rev) >= 32)
    {
        return 0;
    }
    else
    {
        return rev;
    }
}
int main()
{
    int ans = reverse(321);
    cout << ans;
    return 0;
}