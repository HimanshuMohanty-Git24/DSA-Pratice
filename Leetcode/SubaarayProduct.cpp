//713. Subarray Product Less Than K
#include<bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res =0;
        int l=0;
        for (int r=0,prod=1;r<nums.size();r++)
        {
            prod*=nums[r];
            while(prod>=k && l<=r)
            {
                prod/=nums[l];
                l++;
            }
            res+=r-l+1;
        }
        return res;
}
int main()
{
   return 0;
}