//287. Find the Duplicate Number
#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
    int max = *max_element(nums.begin(), nums.end());
    vector<int> freq(max+1,0);
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
    }
    for (int i = 0; i < max+1; i++)
    {
        if(freq[i]>1){
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums={1,3,4,2,2};
    cout<<findDuplicate(nums);
    return 0;
}