// 31. Next Permutation
#include <bits/stdc++.h>
using namespace std;
// Better solution
void nextPermutation1(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}
// Best solution
void nextPermutation2(vector<int> &nums)
{
    int index = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i >= index; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index + 1, nums.end());
}
int main()
{
    vector<int> nums = {3, 2, 1};
    nextPermutation2(nums);
    for (auto i : nums)
        cout << i << " ";
    return 0;
}