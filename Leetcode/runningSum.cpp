// 1480. Running Sum of 1d Array
#include <bits/stdc++.h>
using namespace std;
vector<int> runningSum(vector<int> &nums)
{
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum = sum + nums[j];
        }
        res.push_back(sum);
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = runningSum(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}