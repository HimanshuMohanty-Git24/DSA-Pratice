//Leaders in array
#include<bits/stdc++.h>
using namespace std;
vector<int> leaders(int arr[], int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n-1; i >= 0; i--)
    {
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(arr[i],maxi);
    }
    sort(ans.begin(),ans.end());
}
int main()
{
    int arr[] = {7,10,4,10,6,5,2}, n = 7;
    vector<int> res = leaders(arr, n);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
   return 0;
}