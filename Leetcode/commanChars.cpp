//1002. Find Common Characters
#include<bits/stdc++.h>
using namespace std;
vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        vector<int> minfreq(26,INT_MAX);
        for(int i=0;i<words.size();i++)
        {
            vector<int> freq(26,0);
            for(int j=0;j<words[i].size();j++)
            {
                freq[words[i][j]-'a']++;
            }
            for(int j=0;j<26;j++)
            {
                minfreq[j]=min(minfreq[j],freq[j]);
            }
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<minfreq[i];j++)
            {
                res.push_back(string(1,'a'+i));
            }
        }
        return res;
}
int main()
{
    vector<string> words;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        words.push_back(s);
    }
    vector<string> res=commonChars(words);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
   return 0;
}