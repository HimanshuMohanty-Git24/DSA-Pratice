//229. Majority Element II
#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> list;
    for (int i = 0; i < n; i++)
    {
        if(list.size()==0||list[0]!=nums[i]){
            int ctr=0;
            for (int j = 0; j < n; j++)
            {
                if(nums[j]==nums[i]){
                    ctr++;
                }
            }
            if(ctr>(n/3)){
                list.push_back(nums[i]);
            }
        }
        if(list.size()==2){
            break;
        }
    }
    return list;
}//Time Complexity: O(n^2) space: O(1)
//better Solution:
vector<int> majorityElement2(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> mpp;
    int min = (n/3)+1;
    vector<int> list;
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
        if(mpp[nums[i]]==min){
            list.push_back(nums[i]);
        }
    }
    return list;
}//Time Complexity: O(n) space: O(n)
//Best Solution:
vector<int> majorityElement3(vector<int>& nums) {
    vector<int> list;
    int n = nums.size();
    int ctr1=0,ctr2=0,el1=INT_MIN,el2=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(ctr1==0&&nums[i]!=el2){
            ctr1=1;
            el1=nums[i];
        }
        else if(ctr2==0&&nums[i]!=el1){
            ctr2=1;
            el2=nums[i];
        }
        else if(el1==nums[i]){
            ctr1++;
        }
        else if(el2 == nums[i]){
            ctr2++;
        }
        else{
            ctr1--;
            ctr2--;
        }
    }
    //Manual Checking
    ctr1=0,ctr2=0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) ctr1++;
        if (nums[i] == el2) ctr2++;
    }
    int mini = int(n / 3) + 1;
    if (ctr1 >= mini) list.push_back(el1);
    if (ctr2 >= mini) list.push_back(el2);
    return list;
}//time: O(n) space: O(1)
int main()
{
    vector<int> nums={3,2,3};
    vector<int> ans=majorityElement3(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
   return 0;
}