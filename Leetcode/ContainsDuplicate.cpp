//217. Contains Duplicate
#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
   sort(nums.begin(),nums.end());
   for (int i = 0; i < nums.size()-1; i++)
   {
        if(nums[i]==nums[i+1]){
            return true;
        }
   }
   return false;
}
int main()
{
    vector<int> nums={-4,5,-2,-4,0};
    if(containsDuplicate(nums)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
   return 0;
}