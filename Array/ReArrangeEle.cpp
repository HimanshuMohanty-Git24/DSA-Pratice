//2149. Rearrange Array Elements by Sign
#include<bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]<0){
            neg.push_back(nums[i]);
        }
        else{
            pos.push_back(nums[i]);
        }
    }
    for (int i = 0; i < nums.size()/2; i++)
    {
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }
    return nums;
}//Time Complexity: O(2n) Space Complexity: O(n)
//Efficeint Solution
vector<int> rearrangeArray1(vector<int>& nums) {
    int n= nums.size();
    vector<int>  ans(n,0);
    int posIndex=0,negIndex=1;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]<0){
            ans[negIndex]=nums[i];
            negIndex=negIndex+2;
        }
        else{
            ans[posIndex]=nums[i];
            posIndex=posIndex+2;
        }
    }
    return ans;
}//Time Complexity: O(n) Space Complexity: O(n)
int main()
{
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> ans = rearrangeArray(nums);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
   return 0;
}