//446. Arithmetic Slices II - Subsequence
#include<bits/stdc++.h>
using namespace std;
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int totalArithmeticSubseqCtr = 0;
    vector<unordered_map<long long, int>> dp(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long diff = static_cast<long long>(nums[i]) - nums[j];
            dp[i][diff] += 1;
            if (dp[j].find(diff) != dp[j].end()) {
                dp[i][diff] += dp[j][diff];
                totalArithmeticSubseqCtr += dp[j][diff];
            }
        }
    }

    return totalArithmeticSubseqCtr;
}
/*
Logic:
1. We use a 2D array dp where dp[i][j] stores the number of arithmetic subsequences with difference j ending at index i.
2. We iterate over the array and for each index i, we iterate over all the indices j < i and find the difference between the elements at indices i and j.
3. We then check if we have already calculated the number of arithmetic subsequences ending at index j with difference diff. If yes, we add that value to dp[i][diff] and also to the total number of arithmetic subsequences.
4. We also increment the count of the number of arithmetic subsequences with difference diff ending at index i.
5. Finally, we return the total number of arithmetic subsequences.
*/
int main()
{
    vector<int> nums = {7,7,7,7,7};
    cout<<numberOfArithmeticSlices(nums);
   return 0;
}