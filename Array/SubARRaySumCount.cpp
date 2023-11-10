//560. Subarray Sum Equals K
#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
    map<int,int> mpp;
    mpp[0]=1;
    int preSum=0,cnt=0;
    for(int i=0;i<nums.size();i++){
        preSum+=nums[i];
        int remove=preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]++;
    }
    return cnt;
}
int main()
{
    vector<int> nums={1,2,3,-3,1,1,1,4,2,-3};
    int k=3;
    cout<<subarraySum(nums,k);
   return 0;
}