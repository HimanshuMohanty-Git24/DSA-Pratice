//2486. Append Characters to String to Make Subsequence
#include<bits/stdc++.h>
using namespace std;
int appendCharacters(string s, string t) {
    int i=0;
    int j=0;
    while(i<s.size() && j<t.size())
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return t.size()-j;
}
int main()
{
   string s,t;
   cin>>s>>t;
   cout<<appendCharacters(s,t);
   return 0;
}