//Linear Serach
#include<bits/stdc++.h>
using namespace std;
int LinearSerach(vector<int> nums,int target){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;
    cout<<LinearSerach(nums,target);
   return 0;
}