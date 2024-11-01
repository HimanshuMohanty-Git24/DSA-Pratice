//1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int i = 0, j;
        for (j = 0; j < nums.size(); ++j) {
            s.insert(nums[j]);
            if (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[i++]));
            }
        }
        return j - i;
}
int main()
{
    vector<int> nums = {8,2,4,7};
    int limit = 4;
    cout<<longestSubarray(nums, limit);
   return 0;
}