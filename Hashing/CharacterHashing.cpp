#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int hash[26]={0};
    for(int i=0;i<s.length();i++)
    {
        hash[s[i]-'a']++;
    }//For capital letters, use s[i]-'A'
    //for all characters, use s[i]-' ' 256
    //Frequency of each character
    for(int i=0;i<26;i++)
    {
        if(hash[i]!=0)
        {
            cout<<char(i+'a')<<" "<<hash[i]<<endl;
        }
    }
   return 0;
}