// 169. Majority Element
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
    int max = *max_element(nums.begin(), nums.end());
    vector<int> arr(max+1,0);
    for (int i = 0; i < nums.size(); i++)
    {
        arr[nums[i]]++;
    }
    int n = arr.size();
    return distance(arr.begin(), max_element(arr.begin(), arr.end()));
}
int main()
{
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<majorityElement(nums);
   return 0;
}