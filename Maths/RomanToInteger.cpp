// 13. Roman to Integer
#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    // Using Unordered Map
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] < m[s[i + 1]])
            ans -= m[s[i]];
        else
            ans += m[s[i]];
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
    return 0;
}