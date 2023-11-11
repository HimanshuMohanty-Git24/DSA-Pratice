//1365. How Many Numbers Are Smaller Than the Current Number
#include<bits/stdc++.h>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int hash[101]={0};
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=0;j<nums[i];j++){
            sum=sum+hash[j];
        }
        ans.push_back(sum);
    }
    return ans;
}
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    vector<int> ans=smallerNumbersThanCurrent(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   return 0;
}