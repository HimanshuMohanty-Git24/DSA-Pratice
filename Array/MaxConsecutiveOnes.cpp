//485. Max Consecutive Ones
#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int ctr=0;
    int maxctr=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]==1){
            ctr++;
            maxctr=max(maxctr,ctr);
        }
        else{
            ctr=0;
        }
    }
    return maxctr;
}
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<findMaxConsecutiveOnes(nums);
   return 0;
}