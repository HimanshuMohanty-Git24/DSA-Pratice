//26. Remove Duplicates from Sorted Array
#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    set<int> s;
    for(int i=0;i<nums.size();i++)
    {
        s.insert(nums[i]);
    }
    nums.clear();
    for(auto i:s)
    {
        nums.push_back(i);
    }
    return nums.size();
}//Time Complexity: O(nlogn)
int removeDuplicates(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(nums[i]!=nums[j])
        {
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;
}//Time Complexity: O(n)
//We can't optimize it more than this because we have to return the size of the array and we have to modify the array in place.
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<removeDuplicates(a)<<endl;
   return 0;
}