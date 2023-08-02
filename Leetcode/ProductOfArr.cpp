//238. Product of Array Except Self
#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    auto it = find(nums.begin(), nums.end(), 0);
    if(it != nums.end()){
        int index = it - nums.begin();
        nums[index]=1;
        int mul=accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
        nums[index]=mul;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i!=index){
                nums[i]=0;
            }
        }
    }else{
        int mul=accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
        cout<<mul;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i]=(mul/nums[i]);
        }
    }
    return nums;
}
int main()
{
    vector<int> nums={-1,1,0,-3,3};
    vector<int> res=productExceptSelf(nums);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}