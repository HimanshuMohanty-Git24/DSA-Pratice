//1207. Unique Number of Occurrences
#include<bits/stdc++.h>
using namespace std;
bool uniqueOccurrences0(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto i:mp)
        {
            if(s.find(i.second)!=s.end())//It exists in the set
                return false;
            s.insert(i.second);//Inserting the value of the map if it is not present in the set
        }
        return true;
}
//using bit manipulation
bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int x=0;
        for(auto i:mp)
        {
            x^=i.second;
        }
        return x==0;
}
/*
Logic:
1. We are using a map to store the frequency of each element
2.we are xor ing the frequency of each element
3. If the frequency of each element is unique then the xor will be 0
4. If the frequency of any element is same then the xor will be non zero
*/
int main()
{
    vector<int> arr={1,2,2,1,1,3};
    cout<<uniqueOccurrences(arr);
   return 0;
}