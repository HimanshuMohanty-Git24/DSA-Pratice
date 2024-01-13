//1347. Minimum Number of Steps to Make Two Strings Anagram
#include<bits/stdc++.h>
using namespace std;
int minSteps(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m)
            return -1;
        int count[26]={0};
        for(int i=0;i<n;i++)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        int res=0;
        for(int i=0;i<26;i++)
        {
            if(count[i]>0)
                res+=count[i];
        }
        return res;
}//Time Complexity: O(n) Space Complexity: O(1)
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<minSteps(s,t);
   return 0;
}