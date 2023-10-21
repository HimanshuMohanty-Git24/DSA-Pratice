//283. Move Zeroes
#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        nums[i]=temp[i];
    }
    for (int i = temp.size(); i < nums.size(); i++)
    {
        nums[i]=0;
    }
}//Time Complexity: O(n) Space Complexity: O(n)
void moveZeroes(vector<int>& nums) {
    int j=-1;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1){
        return;
    }
    for (int i = j+1; i < nums.size(); i++)
    {
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
}//Time Complexity: O(n) Space Complexity: O(1)
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
    moveZeroes(nums);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
   return 0;
}