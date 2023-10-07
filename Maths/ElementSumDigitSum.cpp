//2535. Difference Between Element Sum and Digit Sum of an Array
#include<bits/stdc++.h>
using namespace std;
int differenceOfSum(vector<int>& nums) {
    int numSum = 0;
    int digitSum=0;
    for (int i = 0; i < nums.size(); i++)
    {
        int temp=nums[i];
        numSum = numSum+temp;
        while (temp>0)
        {
            digitSum=digitSum+temp%10;
            temp=temp/10;
        }
    }
    return abs(numSum-digitSum);
}//Time Complexity : O(n) Space Complexity : O(1)
int main()
{
    vector<int> nums={1,15,6,3};
    cout<<differenceOfSum(nums);
    return 0;
}