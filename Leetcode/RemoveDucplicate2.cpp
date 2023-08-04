//80. Remove Duplicates from Sorted Array II
#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
   int i=0;
   for(auto e:nums){
      if(i==0||i==1||nums[i-2]!=e){
         nums[i]=e;
         i+=1;
      }
   }
   return i;
}
int main()
{
   vector<int> nums={0,0,1,1,1,1,2,3,3};
   cout<<removeDuplicates(nums);
   return 0;
}