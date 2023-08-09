#include <bits/stdc++.h>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int i = 0;
    int j=nums.size()-1;
    while(i<j){
        int sum=nums[i]+nums[j];
        if(sum==target){
            res.push_back(i);
            res.push_back(j);
            return res;
        }
        if(sum>target){
            if(nums[i]>nums[j]){
                i++;
            }
            else{
                j--;
            }
        }
        else if(sum<target){
            if(nums[i]<nums[j]){
                i++;
            }
            else{
                j--;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums={3,2,4};
    int target=6;
    vector<int> res=twoSum(nums,target);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}
