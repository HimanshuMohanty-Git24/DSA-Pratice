// 35. Search Insert Position
#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        return l;
}
int main()
{
    vector<int> nums = {1,3,5,6};
    int target = 7;
    cout<<searchInsert(nums,target);
   return 0;
}