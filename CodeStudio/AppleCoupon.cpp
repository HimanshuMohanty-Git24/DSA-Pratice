#include <bits/stdc++.h>
using namespace std;
long long appleAndCoupon(int n, int m, vector<int> arr)
{
    sort(arr.begin(), arr.end());
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    int sum = 0;
    for (int i = n - 1; i > n - m; i--)
    {
        sum = sum + arr[i];
    }
    for (int i = 0; i < n - m; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int main()
{
    int n = 4, m = 2;
    vector<int> arr = {2, 3, 1, 5};
    cout << "\nTotal coins used:" << appleAndCoupon(n, m, arr);
    return 0;
}