//268. Missing Number
#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    int xor1=0,xor2=0;
    for(int i=0;i<nums.size();i++)
    {
        xor1^=nums[i];
        xor2^=i;
    }
    xor2^=nums.size();
    return xor1^xor2;
}//Time Complexity: O(n) Space Complexity: O(1)
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    cout<<missingNumber(nums)<<endl;
   return 0;
}