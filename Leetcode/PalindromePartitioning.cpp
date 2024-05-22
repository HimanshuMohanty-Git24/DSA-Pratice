//131. Palindrome Partitioning
#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void dfs(string s, int start, vector<string>& path, vector<vector<string>>& res) {
    if(start == s.size()) {
        res.push_back(path);
        return;
    }
    for(int i=start;i<s.size();i++) {
        if(isPalindrome(s,start,i)) {
            path.push_back(s.substr(start,i-start+1));
            dfs(s,i+1,path,res);
            path.pop_back();
        }
    }
}



vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    dfs(s,0,path,res);
    return res;
}

int main()
{
    string s = "aab";
    vector<vector<string>> res = partition(s);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
   return 0;
}