//300. Longest Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
        return 0;
    vector<int> dp(n,1);
    int ans=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}//Time Complexity: O(n^2) Space Complexity: O(n)
/*
Explain like i am 5:
1. Create a dp array of size n and initialize it with 1.
2. Now for each element in the array, we check if there is any element before it which is smaller than it.
3. If yes, then we check if the length of the subsequence ending at that element is greater than the current length of the subsequence ending at the current element.
4. If yes, then we update the length of the subsequence ending at the current element.
5. Finally, we return the maximum length of the subsequence.
*/
int main()
{
    vector<int> nums={7,7,7,7,7,7,7};
    cout<<lengthOfLIS(nums);
    return 0;
}