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
/*
Logic:
1. If there are even number of negative numbers, then the product of all the numbers is the answer.
2. If there are odd number of negative numbers, then the answer is either the product of all the numbers except the first negative number or the product of all the numbers except the last negative number.
3. If there are no negative numbers, then the answer is the product of all the numbers.
4.if 0 is present in the array, then the answer is the maximum of the above three answers.
*/
int main()
{
    vector<int> nums = {2,3,-2,4};
    cout<<maxProduct(nums)<<endl;
    return 0;
}