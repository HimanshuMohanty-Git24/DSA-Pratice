//100168. Minimum Number of Operations to Make Array XOR Equal to K
#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums, int k) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        if(xorSum==k) return 0;
        int result = 0;
        k ^= xorSum;//k=xorSum^k
        while (k > 0) {
            result += k & 1;
            k >>= 1;
        }
        return result;
}
/*
Logic:
1. Find xorSum of all elements in nums.
2. Find xorSum of all elements in nums and k.
3. Find the number of bits in xorSum of nums and k.
4. Return the number of bits.
*/
int main()
{
    vector<int> nums = {2,0,2,0};
    int k=0;
    cout << minOperations(nums,k) << endl;
    return 0;
}