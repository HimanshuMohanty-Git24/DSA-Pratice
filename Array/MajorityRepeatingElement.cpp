//169. Majority Element
//Moores voters algorithm
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
        int ctr=0;
        int el;
        for(int i=0;i<nums.size();i++){
            if(ctr==0){
                ctr=1;
                el=nums[i];
            }
            else if(nums[i]==el){
                ctr++;
            }
            else{
                ctr--;
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el){
                count++;
            }
        }
        if(count>=nums.size()/2){
            return el;
        }
        return -1;
}
int main()
{
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<majorityElement(nums);
   return 0;
}