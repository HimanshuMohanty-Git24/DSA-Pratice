#include <bits/stdc++.h>
using namespace std;
long long threeWaySplit(int n, int arr[])
{
    long long sumi = 0, sumj = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        sumi = sumi + arr[i];
        if (sumi == sumj)
        {
            ans = sumi;
            break;
        }
        sumj = sumj + arr[n - i - 1];
        if (arr[i] > arr[n - i - 1])
        {
            sumj = sumj + arr[n - i + 1 - 1];
        }
        if (sumi == sumj)
        {
            ans = sumi;
            break;
        }
    }
    return ans;
}
int main()
{
    int arr[5] = {5, 2, 4, 1, 4};
    cout << endl
         << threeWaySplit(5, arr);
    return 0;
}
