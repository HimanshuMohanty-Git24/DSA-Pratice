//2870. Minimum Number of Operations to Make Array Empty
#include<bits/stdc++.h>
using namespace std;
/*
possible operations to empty array:
You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.
*/
int minOperations(vector<int>& nums) {
    map<int,int> dp;
    int n = nums.size();
    for(auto i:nums){
        dp[i]++;
    }
    int c=0;
    for(auto i:dp){
        if(i.second==1){
            return -1;
        }
        c = c+ceil(i.second/(3*1.0));
    }
    return c;
}//Time Complexity: O(nlogn) Space Complexity: O(n)
int main()
{
    vector<int> nums = {14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12};
    cout<<minOperations(nums);
   return 0;
}