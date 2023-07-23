// 2357. Make Array Zero by Subtracting Equal Amounts
#include<bits/stdc++.h>
using namespace std;
int minimumOperations(vector<int> nums) {
    if(nums.size()==0){
        if(nums[0]==0){
            return 0;
        }
        else{
            return 1;
        }
    }
    int operation=0;
    for (int i = 0; i < nums.size(); i++)
    {
        int subs = nums[i];
        for (int j = 0; j < nums.size(); j++)
        {
            if(nums[j]!=0){
                nums[j]=nums[j]-subs;
            }
        }
        if(accumulate(nums.begin(), nums.end(), 0)!=0){
            operation++;
        }
    }
    return operation;
}
int main()
{
    vector<int> nums={1,2,3,5};
    cout<<minimumOperations(nums);
    return 0;
}