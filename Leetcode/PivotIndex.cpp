#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int> &nums) // O(n^2)
{
    int n = nums.size();
    int leftsum, rightsum;
    for (int i = 0; i < n; i++)
    {
        leftsum = 0;
        rightsum = 0;
        for (int j = 0; j < i; j++)
        {
            leftsum = leftsum + nums[j];
        }
        for (int k = i + 1; k < n; k++)
        {
            rightsum = rightsum + nums[k];
        }
        if (leftsum == rightsum)
        {
            return i;
        }
    }
    return -1;
}
int pivotIndex2(vector<int> &nums) // O(n)
{
    if (nums.empty() || nums.size() == 1)
    {
        return 0;
    }
    int leftSum = 0, rightSum = 0;
    for (int num : nums)
    {
        rightSum += num;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        rightSum -= nums[i];
        if (leftSum == rightSum)
        {
            return i;
        }

        leftSum += nums[i];
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 1, -1};
    int ans = pivotIndex(arr);
    cout << ans;

    return 0;
}