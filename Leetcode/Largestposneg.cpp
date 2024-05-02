// 2441. Largest Positive Integer That Exists With Its Negative
#include <bits/stdc++.h>
using namespace std;
int findMaxK(vector<int> &nums)
{
    int n = nums.size(), l = 0, r = n - 1;
    sort(nums.begin(), nums.end());
    while (l < r && nums[l] != -nums[r])
    {
        if (-nums[l] > nums[r])
            l++;
        else
            r--;
    }
    return (l < r) ? nums[r] : -1;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, -1, -2, -3, -4, -5};
    cout << findMaxK(nums) << endl;
    return 0;
}