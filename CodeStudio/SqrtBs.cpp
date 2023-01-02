#include <bits/stdc++.h>
using namespace std;
int sqrtN(long long int N)
{
    if (N < 2)
    {
        return N;
    }
    int low = 0;
    int high = N;
    long long int mid = low + (high - low) / 2;
    long long int ans = -1;
    while (low <= high)
    {
        if ((mid * mid) == N)
        {
            return mid;
        }
        else if ((mid * mid) > N)
        {
            ans = mid - 1;
            high = mid - 1;
        }
        else if ((mid * mid) < N)
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}
int main()
{
    long long int N;
    cin >> N;
    int res = sqrtN(N);
    cout << res;
    return 0;
}