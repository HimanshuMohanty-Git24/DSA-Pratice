//409. Longest Palindrome
#include<bits/stdc++.h>
using namespace std;
int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int count=0;
        int flag=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second%2==0)
            {
                count+=it->second;
            }
            else
            {
                count+=it->second-1;
                flag=1;
            }
        }
        if(flag==1)
        {
            count++;
        }
        return count;
    }
int main()
{
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
   return 0;
}