//88. Merge Sorted Array
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1,j=n-1;
    int k=n+m-1;
    while(i>=0&&j>=0)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[k]=nums1[i];
            i--;
        }
        else {
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }
    while(i>=0)
    {
        nums1[k]=nums1[i];
        i--;
        k--;
    }
    while(j>=0)
    {
        nums1[k]=nums2[j];
        j--;
        k--;
    }
}
int main()
{
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    int m = 3, n = 3;
    merge(nums1,m,nums2,n);
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i]<<" ";
    }
   return 0;
}