//100106. Minimum Sum of Mountain Triplets I
// Example 1:

// Input: nums = [8,6,1,5,3]
// Output: 9
// Explanation: Triplet (2, 3, 4) is a mountain triplet of sum 9 since: 
// - 2 < 3 < 4
// - nums[2] < nums[3] and nums[4] < nums[3]
// And the sum of this triplet is nums[2] + nums[3] + nums[4] = 9. It can be shown that there are no mountain triplets with a sum of less than 9.
// Example 2:

// Input: nums = [5,4,8,7,10,2]
// Output: 13
// Explanation: Triplet (1, 3, 5) is a mountain triplet of sum 13 since: 
// - 1 < 3 < 5
// - nums[1] < nums[3] and nums[5] < nums[3]
// And the sum of this triplet is nums[1] + nums[3] + nums[5] = 13. It can be shown that there are no mountain triplets with a sum of less than 13.
// Example 3:

// Input: nums = [6,5,4,3,4,5]
// Output: -1
// Explanation: It can be shown that there are no mountain triplets in nums.
#include<bits/stdc++.h>
using namespace std;
//My approach:
int minimumSum1(vector<int>& nums) {
    int minsum = INT_MAX;
    int n = nums.size();

    for (int i = 0; i <= n - 3; i++) {
        for (int j = i + 1; j <= n - 2; j++) {
            for (int k = j + 1; k <= n - 1; k++) {
                if (i < j && j < k && nums[i] < nums[j] && nums[j] > nums[k]) {
                    int ans = nums[i] + nums[j] + nums[k];
                    minsum = min(minsum, ans);
                }
            }
        }
    }

    return (minsum == INT_MAX) ? -1 : minsum;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    cout<<minimumSum1(nums)<<endl;
   return 0;
}