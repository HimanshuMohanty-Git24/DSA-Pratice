//3152. Special Array II
#include<bits/stdc++.h>
using namespace std;
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<bool> res;
    for (auto q : queries) {
        int l = q[0], r = q[1];
        bool is_special = true;
        for (int i = l; i < r; i++) {
            if ((nums[i] % 2) == (nums[i + 1] % 2)) {
                is_special = false;
                break;
            }
        }
        res.push_back(is_special);
    }
    return res;
}
int main()
{
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0,4}};
    vector<bool> res = isArraySpecial(nums, queries);
    for(auto i: res){
        cout<<i<<" ";
    }
   return 0;
}