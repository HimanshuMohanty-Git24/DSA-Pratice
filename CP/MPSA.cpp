#include<bits/stdc++.h>
using namespace std;
int MPSA(vector<int>& nums){
    if(nums.size()==1){
        return nums[0];
    }
    int res=0;
    int currMin=1,currMax=1;
    for(auto num:nums){
        if(num==0){//if there is a zero make reset the currMax and currMin as anything multiplied to zero is 0 and we need a fresh start
            currMin=1;
            currMax=1;
        }
        int tmp=num*currMax;
        currMax=max({num*currMax,num*currMin,num});
        currMin=min({tmp,num*currMin,num});
        res = max({res,currMax});
    }
    return res;
}
int MPSA2(vector<int>& nums){
    if(nums.size()==1){
        return nums[0];
    }
    int res=INT_MIN;
    int prefix=1,suffix=1;
    for(int i=0;i<nums.size();i++){
        prefix = prefix*nums[i];
        suffix = suffix*nums[nums.size()-i-1];
        res = max({prefix,suffix,res});
        if(prefix==0){
            prefix==1;
        }
        if(suffix==0){
            suffix=1;
        }
    }
    return res;
}
int main()
{
    vector<int> nums = {0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0};
    cout<<MPSA2(nums)<<endl;
   return 0;
}