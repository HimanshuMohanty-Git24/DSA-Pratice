// 26. Remove Duplicates from Sorted Array
#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    int n = nums.size();
    int i = 0;
    int j=1;
    while (j<n)
    {
        if(nums[j]!=nums[i]){
            i++;
            nums[i]=nums[j];
        }
        j++;
    }

    return i+1;
}
int main()
{
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(nums);
   return 0;
}