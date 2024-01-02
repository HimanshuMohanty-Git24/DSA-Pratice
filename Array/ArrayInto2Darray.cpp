//2610. Convert an Array Into a 2D Array With Conditions

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findMatrix(vector<int>& nums) {
    int n =0;
    map<int,int> m;

    for (auto x:nums)//Calculating the highest occurance of element = number of rows of 2D array
    {
        m[x]++;
        n=max(n,m[x]);
    }
    vector<vector<int>> ans(n);//2d array of n rows
    vector<set<int>> s(n);//set of n rows

    for(auto x: nums){
        for(int i=0;i<n;i++){
            if(s[i].find(x)==s[i].end()){//if element is not present in the set of ith row
                ans[i].push_back(x);//push the element in the ith row of 2d array
                s[i].insert(x);//insert the element in the set of ith row
                break;
            }
        }
    }
    return ans;
}
//Time Complexity: O(nlogn) Space Complexity: O(n)
/*
Logic:
1. Find the highest occurance of element in the array
2. Create a 2D array of n rows
3. Create a set of n rows
4. Traverse the array and check if the element is present in the set of ith row
5. If not present, push the element in the ith row of 2D array and insert the element in the set of ith row
6. If present, move to the next row
*/
int main()
{
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> res = findMatrix(nums);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}