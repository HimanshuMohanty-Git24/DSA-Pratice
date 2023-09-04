// 283. Move Zeroes
#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums){
    if(nums.size()==1&&nums[0]==0){
        nums[0]=nums[0];
    }
    for (int i = 0; i < nums.size()-1; )
    {
        for (int j = i+1; j < nums.size();)
        {
            if(nums[i]!=0){
                break;
            }
            else{
                if(nums[j]!=0){
                    int temp = nums[i];
                    nums[i]= nums[j];
                    nums[j]=temp;
                }
                else{
                    j++;
                }
            }
        }
        i++;
    }
    for(auto num:nums){
        cout<<num<<" ";
    }

}
int main()
{
    vector<int> nums ={0,1,0,3,12};
    moveZeroes(nums);
   return 0;
}
