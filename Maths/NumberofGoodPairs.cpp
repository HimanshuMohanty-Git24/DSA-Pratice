//1512. Number of Good Pairs
#include<bits/stdc++.h>
using namespace std;
int numIdenticalPairs(vector<int>& nums) {
    int ctr=0;
    int n=nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j>i ; j--)
        {
            if(nums[i]==nums[j]){
                ctr++;
            }
        }
    }
    return ctr;
}
int main()
{
    vector<int> nums={1,2,3};
    cout<<numIdenticalPairs(nums);
    return 0;
}