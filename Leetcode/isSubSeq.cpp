// 392. Is Subsequence
#include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t)
{
    int i, j;
    for (i = 0, j = 0; i < s.length() && j < t.length(); j++)
    {
        if (s[i] == t[j])
        {
            i++;
        }
    }
    return i == s.length();
}
int main()
{
    string s, t;
    s="abc";
    t="ahbgdc";
    if (isSubsequence(s, t))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}