//2780. Minimum Index of a Valid Split
#include<bits/stdc++.h>
using namespace std;
int minimumIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0), suffix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + (nums[i] == 1 ? 1 : -1);
    }
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + (nums[i] == 1 ? 1 : -1);
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (prefix[i + 1] > suffix[i + 1]) {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    cout << minimumIndex(nums) << endl; // Output: 2
    nums = {0, 1, 0, 1, 0};
    cout << minimumIndex(nums) << endl; // Output: 0
    nums = {1, 1, 1, 0, 0};
    cout << minimumIndex(nums) << endl; // Output: 2

   return 0;
}