//2903. Find Indices With Index and Value Difference I

#include<bits/stdc++.h>
using namespace std;
vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if(abs(i-j)>= indexDifference && abs(nums[i]-nums[j])>=valueDifference){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}//Time Complexity: O(n^2)
int main()
{
    vector<int> nums={1,2,3};
    int indexDifference=2;
    int valueDifference=4;
    vector<int> ans=findIndices(nums,indexDifference,valueDifference);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }//0 2
    return 0;
}