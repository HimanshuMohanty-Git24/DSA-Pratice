//349. Intersection of Two Arrays
#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int n1=nums1.size();
    int n2=nums2.size();
    if(n1>n2){
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                if(nums1[j]==nums2[i]&&count(res.begin(), res.end(), nums2[i])==0){
                    res.push_back(nums1[j]);
                }
            }
        }
    }else{
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if(nums2[j]==nums1[i]&&count(res.begin(), res.end(), nums1[i])==0){
                    res.push_back(nums2[j]);
                }
            }
        }
    }
    return res;
}
int main()
{
    vector<int> num1 ={4,9,5};
    vector<int> num2 ={9,4,9,8,4};
    vector<int> res=intersection(num1,num2);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}