//152. Maximum Product Subarray
#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}//Time Complexity: O(n) Space Complexity: O(1)
int main()
{
    vector<int> nums = {2,3,-2,4};
    cout<<maxProduct(nums)<<endl;
    return 0;
}