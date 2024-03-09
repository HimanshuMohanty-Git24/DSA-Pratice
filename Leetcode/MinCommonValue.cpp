//2540. Minimum Common Value
#include<bits/stdc++.h>
using namespace std;
int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        while( p1 < n1 && p2 < n2) {
            if(nums1[p1] == nums2[p2])
               return nums1[p1];
            else if(nums1[p1] < nums2[p2])
               p1++;
            else
               p2++;
        }
        return -1;
}
int main()
{
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4};
    cout<<getCommon(nums1,nums2);
   return 0;
}