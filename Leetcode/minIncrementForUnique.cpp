//945. Minimum Increment to Make Array Unique
#include<bits/stdc++.h>
using namespace std;
int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                ans+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return ans;
}
/*
Logic:
1. Sort the array
2. Traverse the array and check if the current element is less than or equal to the previous element
3. If yes, then increment the current element to previous element + 1 and add the difference to the answer
4. Return the answer
*/
int main()
{
    vector<int>nums={1,2,2};
    cout<<minIncrementForUnique(nums);
   return 0;
}