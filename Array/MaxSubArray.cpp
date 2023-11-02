//53. Maximum Subarray
#include<bits/stdc++.h>
using namespace std;
int maxSubArray1(vector<int>& nums) {
    int maxsum=INT_MIN;
    int n =nums.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            maxsum= max(maxsum, sum);
        }
    }
    return maxsum;
}//O(n^3)
int maxSubArray2(vector<int>& nums) {
    int maxsum=INT_MIN;
    int n =nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            maxsum= max(maxsum, sum);
        }
    }
    return maxsum;
}//O(n^2)
int maxSubArray3(vector<int>& nums) {//Kadane's Algorithm
    int start;
    int anstart,ansend;
    int maxsum=INT_MIN;
    int n =nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum==0){
            start =i;
        }//if sum is 0 then start from i
        sum+=nums[i];
        if(sum>maxsum){
            maxsum=sum;
            anstart=start;
            ansend=i;
        }//if sum is greater than maxsum then update maxsum and start and end index
        if(sum<0){
            sum=0;
        }
    }
    //Printing the subarray
    cout<<"Subarray is: ";
    for(int i=anstart;i<=ansend;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return maxsum;
}//O(n)
int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray3(nums);
   return 0;
}