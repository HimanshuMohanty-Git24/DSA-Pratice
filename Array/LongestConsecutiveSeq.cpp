//128. Longest Consecutive Sequence
#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    sort(nums.begin(),nums.end());
    int longest=1,countcurr=0,lastSmaller=INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]-1 == lastSmaller){
            countcurr=countcurr+1;
            lastSmaller=nums[i];
        }
        else if(nums[i]==lastSmaller){
            continue;
        }
        else if(nums[i]!=lastSmaller){
            countcurr=1;
            lastSmaller=nums[i];
        }
        longest=max(longest,countcurr);
    }
    return longest;
}//Time Complexity: O(nlogn) Space Complexity: O(1)
//optimal solution
int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    int longest=1;
    for (int i = 0; i < nums.size(); i++)
    {
        if(s.find(nums[i]-1)==s.end()){
            int curr=nums[i];
            int count=1;
            while(s.find(curr+1)!=s.end()){
                curr=curr+1;
                count=count+1;
            }
            longest=max(longest,count);
        }
    }
    return longest;
}//Time Complexity: O(n) Space Complexity: O(n)
int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    cout<<longestConsecutive(nums);
   return 0;
}