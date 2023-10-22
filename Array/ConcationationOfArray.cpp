//1929. Concatenation of Array
#include<bits/stdc++.h>
using namespace std;
vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2*n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
            ans[i+n]=nums[i];
        }
        return ans;
}
int main()
{
    vector<int> nums={1,2,3,4};
    vector<int> ans=getConcatenation(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   return 0;
}