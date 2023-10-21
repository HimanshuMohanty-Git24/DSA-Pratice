//349. Intersection of Two Arrays
#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //2 pointer approach sorted array
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int i=0,j=0;
    vector<int> ans;
    while(i<nums1.size() && j<nums2.size())
    {
        if(nums1[i]==nums2[j])
        {
            if(ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}//Time Complexity: O(nlogn+mlogm) Space Complexity: O(1)
vector<int> intersectionReal(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        while(i<n&&j<m){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums2[j]<nums1[i]){
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
}//Time Complexity: O(n+m) Space Complexity: O(1)
int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = intersection(nums1,nums2);
    vector<int> ans1 = intersectionReal(nums1,nums2);
    cout<<"Intersection of two arrays is(Leetcode version): ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"Intersection of two arrays is: ";
    for(int i=0;i<ans1.size();i++)
    {
        cout<<ans1[i]<<" ";
    }
   return 0;
}