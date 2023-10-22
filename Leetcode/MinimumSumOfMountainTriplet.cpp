//100106. Minimum Sum of Mountain Triplets I
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