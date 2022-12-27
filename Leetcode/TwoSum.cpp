#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}
int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target;
    cin >> target;
    vector<int> res = twoSum(arr, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}