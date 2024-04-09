//645. Set Mismatch
#include<bits/stdc++.h>
using namespace std;
vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int arr[n+1]={0};
        for(int i=0;i<n;i++)
        {
            arr[nums[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==2)
            {
                ans.push_back(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
}
//o(n) and o(1) solution
vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0)
            {
                ans.push_back(abs(nums[i]));
            }
            else
            {
                nums[abs(nums[i])-1]*=-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
}//o(n) and o(1) solution
int main()
{
    vector<int> nums={1,2,2,4};
    vector<int> ans=findErrorNums(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
   return 0;
}