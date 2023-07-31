//228. Summary Ranges
#include<bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && nums[j + 1] == nums[j] + 1) {
            j++;
        }
        if (j == i) {
            ranges.push_back(to_string(nums[i]));
        } else {
            ranges.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            i = j;
        }
    }
    return ranges;
}

int main()
{
    vector<int> nums={0,1,2,4,5,7};
    vector<string> ans=summaryRanges(nums);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
   return 0;
}