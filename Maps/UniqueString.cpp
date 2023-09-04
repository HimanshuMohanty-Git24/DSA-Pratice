//Given N string and Q queries, print the frequency of each string
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        //m[s]=m[s]+1;
        m[s]++;
    }
    for(auto pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
   return 0;
}