//219. Contains Duplicate II
#include<bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        if (seen.count(nums[i]) && i - seen[nums[i]] <= k) {
            return true;
        }
        seen[nums[i]] = i;
    }
    return false;
}
int main()
{
    vector<int> nums={1,2,3,1,2,3};
    int k=2;
    if(containsNearbyDuplicate(nums,k)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}