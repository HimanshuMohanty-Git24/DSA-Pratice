//1122. Relative Sort Array
#include<bits/stdc++.h>
using namespace std;
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int,int> mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]>0){
                res.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            while(it->second>0){
                res.push_back(it->first);
                it->second--;
            }
        }
        return res;
}
int main()
{
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> res = relativeSortArray(arr1,arr2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
   return 0;
}