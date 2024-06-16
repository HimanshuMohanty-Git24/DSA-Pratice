//974. Subarray Sums Divisible by K
#include<bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int rem = sum%k;
            if(rem<0)
                rem += k;
            if(mp.find(rem)!=mp.end())
                count += mp[rem];
            mp[rem]++;
        }
        return count;
}
int main()
{
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    cout<<subarraysDivByK(nums,k)<<endl;//output: 7

    vector<int> nums1 = {5};
    int k1 = 9;
    cout<<subarraysDivByK(nums1,k1)<<endl;//output: 0
   return 0;
}