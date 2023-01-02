#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int N)
{
    int ans = -1;
    if (N < 2)
    {
        ans = N;
    }
    int low = 0;
    int high = N;
    long long int mid = low + (high - low) / 2;
    while (low <= high)
    {
        long long int square = mid * mid;
        if ((square) == N)
        {
            return true;
        }
        else if ((square) > N)
        {
            high = mid - 1;
        }
        else if ((square) < N)
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return false;
}
int main()
{
    int x = 14;
    bool ans = isPerfectSquare(x);
    if (ans)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}