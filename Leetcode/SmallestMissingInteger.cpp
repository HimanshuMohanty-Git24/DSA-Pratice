//100157. Smallest Missing Integer Greater Than Sequential Prefix Sum
#include<bits/stdc++.h>
using namespace std;

bool contains(vector<int> nums, int value) {
        for (int num : nums) {
            if (num == value) {
                return true;
            }
        }
        return false;
}
int missingInteger(vector<int>& nums) {
     int ps = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                ps += nums[i];
            } else {
                break;
            }
        }

        int missInt = ps;
        while (contains(nums, missInt)) {
            missInt++;
        }
        return missInt;
}
int main()
{
    vector<int> nums = {1,2,3,2,5};
    cout << missingInteger(nums) << endl;
    return 0;
}