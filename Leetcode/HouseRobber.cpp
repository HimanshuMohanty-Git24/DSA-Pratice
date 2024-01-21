//198. House Robber
#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
    int rob1 = 0;
    int rob2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int temp = max(rob1 + nums[i], rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}//time O(n) space O(1)
int main()
{
    vector<int> nums = {1,2,3,1};
    cout<<rob(nums)<<endl;
   return 0;
}