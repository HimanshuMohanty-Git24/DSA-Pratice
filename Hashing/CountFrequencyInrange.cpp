//Count Frequency in a range
#include<bits/stdc++.h>
using namespace std;
vector<int> countFrequency(int n, int x, vector<int> &nums){
    map<int,int> m;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for (int i = 0; i < m.size(); i++)
    {
        res.push_back(m[i]);
    }
    return res;
}
int main()
{
    int n=6;
    int x=9;
    vector<int> arr={1,3,1,9,2,7};
    vector<int> res = countFrequency(n,x,arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<endl;
    }
}