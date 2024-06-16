//100327. Find the Maximum Length of a Good Subsequence II
#include <bits/stdc++.h>
using namespace std;

int maximumLength(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 1));
    int maxLength = 1;

    vector<int> maxLengthWithJDiffs(k + 1, -1);
    vector<map<int, int>> maxLengthWithJDiffsForValue(k + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l < j; l++) {
                dp[i][j] = max(dp[i][j], 1 + maxLengthWithJDiffs[l]);
            }
            if (maxLengthWithJDiffsForValue[j].find(nums[i]) != maxLengthWithJDiffsForValue[j].end()) {
                dp[i][j] = max(dp[i][j], 1 + maxLengthWithJDiffsForValue[j][nums[i]]);
            }
            maxLength = max(maxLength, dp[i][j]);
        }
        for (int j = 0; j <= k; j++) {
            maxLengthWithJDiffs[j] = max(maxLengthWithJDiffs[j], dp[i][j]);
            maxLengthWithJDiffsForValue[j][nums[i]] = max(maxLengthWithJDiffsForValue[j][nums[i]], dp[i][j]);
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums = {1, 2, 1, 1, 3};
    int k = 2;
    cout << maximumLength(nums, k) << endl; // Output: 4

    vector<int> nums1={1,2,3,4,5,1};
    int k2=0;
    cout << maximumLength(nums1, k2) << endl; // Output: 0

    return 0;
}
