#include <bits/stdc++.h>
using namespace std;
bool isPossible(int barrier, vector<int> &weights, int days, int sum)
{
    int DayCtr = 1;
    int WeightAllocated = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        WeightAllocated = WeightAllocated + weights[i];
        if (WeightAllocated > barrier)
        {
            DayCtr++;
            WeightAllocated = weights[i];
        }
    }
    if (DayCtr > days)
    {
        return false;
    }
    return true;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int ans;
    int low = *max_element(weights.begin(), weights.end());
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum = sum + weights[i];
    }
    int high = sum;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (isPossible(mid, weights, days, sum)) // Search in the lower bound
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}
int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int res = shipWithinDays(weights, days);
    cout << "least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within" << days << " days is:" << res << endl;
    return 0;
}