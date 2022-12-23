/*7. Reverse Integer*/
#include <bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    int r, rev = 0;
    while (x != 0)
    {
        r = x % 10;
        if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) // here we check that is a*10 is out of our range if it is out of int range we return 0
        {
            return 0;
        }
        x = x / 10;
        rev = rev * 10 + r; // Here it may go out of the space constrain in the question so we put a check at the top to stop this exception
    }

    return rev;
}
int main()
{
    int ans = reverse(321);
    cout << ans;
    return 0;
}