//1470. Shuffle the Array
#include<bits/stdc++.h>
using namespace std;
vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans;
    int i=0,j=n;
    while (i<n+1&&j<n*2)
    {
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
        i++;
        j++;
    }
    return ans;
}//Time Complexity: O(n) Space Complexity: O(n)
int main()
{
    vector<int> nums ={1,1,2,2};
    int n=2;
    vector<int> ans = shuffle(nums,n);
    cout<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
   return 0;
}