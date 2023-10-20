//1752. Check if Array Is Sorted and Rotated
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& nums) {
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i]>nums[(i+1)%n]) count++;//(i+1)%n is used to check the last element with the first element
    }
    return count<=1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<check(a)<<endl;
   return 0;
}