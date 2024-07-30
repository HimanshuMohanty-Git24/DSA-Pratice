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
int main()
{
    vector<int> nums = {0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0};
    cout<<MPSA(nums)<<endl;
   return 0;
}