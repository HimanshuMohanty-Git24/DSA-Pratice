//100331. Find the Maximum Length of a Good Subsequence I
#include <bits/stdc++.h>
using namespace std;

int maximumLength(vector<int>& nums, int maxTransitions) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(maxTransitions + 1, 0));

    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }

    int maxLength = 1;

    for (int i = 1; i < n; ++i) {
        for (int t = 0; t <= maxTransitions; ++t) {
            dp[i][t] = 1;
            for (int p = 0; p < i; ++p) {
                if (nums[p] == nums[i]) {
                    dp[i][t] = max(dp[i][t], dp[p][t] + 1);
                } else if (t > 0) {
                    dp[i][t] = max(dp[i][t], dp[p][t - 1] + 1);
                }
            }
            maxLength = max(maxLength, dp[i][t]);
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums1 = {1, 2, 1, 1, 3};
    int k1 = 2;
    cout << maximumLength(nums1, k1) << endl; // Output: 4

    vector<int> nums2 = {1, 2, 3, 4, 5, 1};
    int k2 = 0;
    cout << maximumLength(nums2, k2) << endl; // Output: 2

    return 0;
}
