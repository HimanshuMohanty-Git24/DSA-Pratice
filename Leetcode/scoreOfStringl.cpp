//3110. Score of a String
#include<bits/stdc++.h>
using namespace std;
int scoreOfString(string s) {
    int ans = 0;
    for (int i = 0; i < s.length()-1; i++)
    {
        ans = abs(int(s[i]) - int(s[i+1])) + ans;
    }
    return ans;
}
int main()
{
    string s = "zaz";
    cout << scoreOfString(s);
    return 0;
}