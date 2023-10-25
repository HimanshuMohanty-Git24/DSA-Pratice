//75. Sort Colors
#include<bits/stdc++.h>
using namespace std;
//Dutch National Flag Algorithm
void sortColors(vector<int>& nums) {
    int n=nums.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}//Time Complexity: O(n) Space Complexity: O(1)
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    sortColors(nums);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
   return 0;
}