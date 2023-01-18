#include <bits/stdc++.h>
using namespace std;
bool canPlaceCows(vector<int> stall, int n, int k, int dis)
{
    int coord = stall[0];
    int Cowcount = 1;
    for (int i = 1; i < n; i++)
    {
        if (stall[i] - coord >= dis)
        {
            Cowcount++;
            coord = stall[i];
        }
        if (Cowcount >= k)
        {
            return true;
        }
    }
    return false;
}
int AggressiveCow(vector<int> stall, int k)
{
    int n = stall.size();
    sort(stall.begin(), stall.end());
    int low = 0, high = stall[n - 1] - stall[0], ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stall, n, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cout << "Enter the number of stalls:" << endl;
    cin >> n;
    vector<int> stall(n);
    cout << "Enter the positions of the stalls:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> stall[i];
    }
    cout << "Enter the number of cows:" << endl;
    cin >> k;
    if (n == 0 || k == 0)
    {
        cout << "Invalid Input" << endl;
        return 0;
    }
    if (n == 1 && k == 1)
    {
        cout << "0" << endl;
        return 0;
    }
    int res = AggressiveCow(stall, k);
    cout << "Minimum distance between any two cows is the maximum possible: " << res;
    return 0;
}