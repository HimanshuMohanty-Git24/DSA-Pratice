//977. Squares of a Sorted Array
#include<bits/stdc++.h>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=pow(nums[i],2);
        }
        sort(nums.begin(),nums.end());
        return nums;
}
int main()
{
    //Predefined array
    vector<int> nums={-4,-1,0,3,10};
    vector<int> result=sortedSquares(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
   return 0;
}