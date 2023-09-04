//1679. Max Number of K-Sum Pairs
#include<bits/stdc++.h>
using namespace std;
int maxOperations(vector<int>& nums, int k) {
    int opCtr=0;
    sort(nums.begin(), nums.end()); // sort the input vector
    int i=0;
    int j=nums.size()-1;
    while (i<j)
    {
        int sum=nums[i]+nums[j];
        if(sum==k){
            opCtr++;
            i++;
            j--;
        }
        else if(sum<k){
            i++;
        }
        else{
            j--;
        }
    }
    return opCtr;
}
int main()
{
    vector<int> nums={4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};
    int k = 2;
    cout<<maxOperations(nums,k);
    return 0;
}