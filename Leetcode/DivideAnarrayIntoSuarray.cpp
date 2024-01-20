// 100181. Divide an Array Into Subarrays With Minimum Cost I
#include <bits/stdc++.h>
using namespace std;
int minimumCost(vector<int> &nums)
{
    int n = nums.size();
    int fmin = 51, smin = 51;
    for (int i = 1; i < n; i++)
    {

        if (nums[i] < fmin)
        {
            smin = fmin;
            fmin = nums[i];
        }
        else if (nums[i] < smin)
        {
            smin = nums[i];
        }
    }
    return nums[0] + fmin + smin;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << minimumCost(nums);
    return 0;
}