// 1248. Count Number of Nice Subarrays
#include <bits/stdc++.h>
using namespace std;
    int subarray(vector<int> nums, int k)
    {
        if (k < 0)
        {
            return 0;
        }
        int n = nums.size();

        int l = 0;
        int r = 0;
        int odd = 0;
        int count = 0;

        while (r < n)
        {
            if (nums[r] % 2)
            {
                odd++;
            }
            while (odd > k)
            {
                if (nums[l] % 2)
                {
                    odd--;
                }
                l++;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return subarray(nums, k) - subarray(nums, k - 1);
    }
int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << numberOfSubarrays(nums, k);
    return 0;
}