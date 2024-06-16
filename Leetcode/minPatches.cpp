//330. Patching Array
#include<bits/stdc++.h>
using namespace std;
int minPatches(vector<int>& nums, int n) {
        long long maxReach = 0;
        int i = 0;
        int count = 0;
        while(maxReach < n)
        {
            if(i < nums.size() && nums[i] <= maxReach + 1)
            {
                maxReach += nums[i];
                i++;
            }
            else
            {
                maxReach += maxReach + 1;
                count++;
            }
        }
        return count;
}
int main()
{
    vector<int> nums = {1, 5, 10};
    int n = 20;
    cout<<minPatches(nums, n);
   return 0;
}