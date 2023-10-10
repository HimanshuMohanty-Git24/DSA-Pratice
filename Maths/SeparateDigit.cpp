//2553. Separate the Digits in an Array
#include<bits/stdc++.h>
using namespace std;
vector<int> separateDigits(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++)
    {
        if(floor(log10(nums[i])+1)>1){
            int temp=nums[i];
            vector<int> temparr;
            while (temp>0)
            {
                temparr.push_back(temp%10);
                temp=temp/10;
            }
            for (int j = temparr.size()-1; j >=0 ; j--)
            {
                res.push_back(temparr[j]);
            }
        }
        else{
            res.push_back(nums[i]);
        }
    }
    return res;
}//time complexity: O(nlogn)
//Alternate Method optimized
vector<int> separateDigits1(vector<int>& nums) {
    vector<int> temp;
        stack<int>s;
        for(int i=0;i<nums.size();i++){
            while(nums[i]){
                int digit=nums[i]%10;
                s.push(digit);
                nums[i]/=10;
            }
            while(!s.empty()){
                temp.push_back(s.top());
                s.pop();
            }
        }
        return temp;
}//Time Complexity: O(nlogn)
int main()
{
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    vector<int> ans=separateDigits(nums);
    cout<<"The array after separating the digits is: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
   return 0;
}