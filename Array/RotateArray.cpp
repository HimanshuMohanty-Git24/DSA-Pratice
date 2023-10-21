//189. Rotate Array
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;//if k>n
        reverse(nums.begin(),nums.end());//reverse whole array
        reverse(nums.begin(),nums.begin()+k);//reverse from 0 to k
        reverse(nums.begin()+k,nums.end());//reverse from k to end
}//TimeComplexity:O(n) SpaceComplexity:O(1)
//Without using any inbuit function
void rotate1(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;//if k>n
        if(n==1||k==0){
           return;
        }
        int temp[k];
        for(int i=0;i<k;i++)
        {
            temp[i]=nums[n-k+i];
        }
        for(int i=n-k-1;i>=0;i--)
        {
            nums[i+k]=nums[i];
        }
        for(int i=0;i<k;i++)
        {
            nums[i]=temp[i];
        }
}//TimeComplexity:O(n) SpaceComplexity:O(k)
int main()
{
    vector<int> nums;
    int n,k;
    cin>>n>>k;//n=7 k=3
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }//1 2 3 4 5 6 7
    rotate1(nums,k);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    
   return 0;
}