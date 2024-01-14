//1657. Determine if Two Strings Are Close
#include<bits/stdc++.h>
using namespace std;
bool closeStrings(string word1, string word2) {
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    vector<int> v11(26,0);
    vector<int> v22(26,0);
    for(auto a:word1){
        v1[a-'a']++;
        v11[a-'a']=1;
    }
    for(auto a:word2){
        v2[a-'a']++;
        v22[a-'a']=1;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    return (v1==v2&&v11==v22);
}//Time Complexity: O(nlogn) Space Complexity: O(n)
//better approach:
bool closeStrings2(string word1, string word2) {
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    for(auto a:word1){
        v1[a-'a']++;
    }
    for(auto a:word2){
        v2[a-'a']++;
    }
    for(int i=0;i<26;i++){
        if((v1[i]==0&&v2[i]!=0)||(v1[i]!=0&&v2[i]==0)) return false;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    return v1==v2;
}//Time Complexity: O(n) Space Complexity: O(n)
int main()
{
    string word1,word2;
    cin>>word1>>word2;
    cout<<closeStrings(word1,word2);
   return 0;
}