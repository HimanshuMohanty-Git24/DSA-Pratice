//Longest Subarray with the sum k
#include<bits/stdc++.h>
using namespace std;
int LongestSubarray(vector<int> arr,int k){
    int len=0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum=0;
        for (int j = i; j < arr.size(); j++)
        {
            // int sum=0;
            // for (int k = i; k <= j; k++)
            // {
            //     sum+=arr[k];
            // }
            sum=sum+arr[j];
            if(sum==k){
                len=max(len,j-i+1);
            }
        }
    }
    return len;
}//Time Complexity:O(n^3) Space Complexity:O(1) Better Brute Time Complexity:O(n^2) Space Complexity:O(1)
//Efficient Solution
int LongestSubarray(vector<int> a,int k){//Most optimal for positive numbers negative numbers and zeros
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}//Time Complexity:O(n) Space Complexity:O(n)
//Most Efficient Solution
int LongestSubarray(vector<int> a,int k){//Most optimal if conarins positive and zeros
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}//Time Complexity:O(n) Space Complexity:O(1)
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    int k=15;
    cout<<LongestSubarray(arr,k);
   return 0;
}