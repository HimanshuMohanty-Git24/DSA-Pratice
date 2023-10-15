// You are given a 0-indexed array nums of non-negative integers, and two integers l and r.

// Return the count of sub-multisets within nums where the sum of elements in each subset falls within the inclusive range of [l, r].

// Since the answer may be large, return it modulo 109 + 7.

// A sub-multiset is an unordered collection of elements of the array in which a given value x can occur 0, 1, ..., occ[x] times, where occ[x] is the number of occurrences of x in the array.

// Note that:

// Two sub-multisets are the same if sorting both sub-multisets results in identical multisets.
// The sum of an empty multiset is 0.
 

// Example 1:

// Input: nums = [1,2,2,3], l = 6, r = 6
// Output: 1
// Explanation: The only subset of nums that has a sum of 6 is {1, 2, 3}.
// Example 2:

// Input: nums = [2,1,4,2,7], l = 1, r = 5
// Output: 7
// Explanation: The subsets of nums that have a sum within the range [1, 5] are {1}, {2}, {4}, {2, 2}, {1, 2}, {1, 4}, and {1, 2, 2}.
// Example 3:

// Input: nums = [1,2,1,3,5,2], l = 3, r = 5
// Output: 9
// Explanation: The subsets of nums that have a sum within the range [3, 5] are {3}, {5}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {1, 1, 2}, {1, 1, 3}, and {1, 2, 2}.
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// 0 <= nums[i] <= 2 * 104
// Sum of nums does not exceed 2 * 104.
// 0 <= l <= r <= 2 * 104
#include<bits/stdc++.h>
using namespace std;
int countSubMultisets(vector<int>& nums, int l, int r) {
    int n=nums.size();
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]*2;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=nums[j];
            if(sum>=l && sum<=r)
            {
                ans+=dp[j-i+1];
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int l,r;
    cin>>l>>r;
    cout<<countSubMultisets(nums,l,r);
   return 0;
}