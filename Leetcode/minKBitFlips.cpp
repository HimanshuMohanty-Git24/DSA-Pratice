//995. Minimum Number of K Consecutive Bit Flips
#include<bits/stdc++.h>
using namespace std;
int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipped = 0;
        int res = 0;
        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }

        return res;
}
int main()
{
    vector<int> nums = {0,1,0};
    int k =1;
    cout<<minKBitFlips(nums,k);
   return 0;
}