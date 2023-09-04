// 136. Single Number
#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    if(nums.size()==1){
        return nums[0];
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i+=2){
        if(nums[i]!=nums[i+1]){
            return nums[i];
        }
    }
}
int main()
{
    vector<int> nums={2,2,1};
    cout<<singleNumber(nums);
   return 0;
}