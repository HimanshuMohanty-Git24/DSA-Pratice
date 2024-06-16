//523. Continuous Subarray Sum
#include<bits/stdc++.h>
using namespace std;
bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int n = nums.size();
        mp[0] = -1;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(k != 0)
                sum = sum % k;
            if(mp.find(sum) != mp.end())
            {
                if(i - mp[sum] > 1)
                    return true;
            }
            else
                mp[sum] = i;
        }
        return false;
}
int main()
{
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout<<checkSubarraySum(nums, k);
   return 0;
}