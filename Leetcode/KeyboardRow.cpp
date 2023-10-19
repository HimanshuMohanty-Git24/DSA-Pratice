// 500. Keyboard Row
#include <bits/stdc++.h>
using namespace std;
vector<string> findWords(vector<string> &words)
{
    vector<string> ans;
    // Using hash map
    unordered_map<char, int> mp;

    // Inserting values in map
    mp['q'] = 1;
    mp['w'] = 1;
    mp['e'] = 1;
    mp['r'] = 1;
    mp['t'] = 1;
    mp['y'] = 1;
    mp['u'] = 1;
    mp['i'] = 1;
    mp['o'] = 1;
    mp['p'] = 1;
    mp['a'] = 2;
    mp['s'] = 2;
    mp['d'] = 2;
    mp['f'] = 2;
    mp['g'] = 2;
    mp['h'] = 2;
    mp['j'] = 2;
    mp['k'] = 2;
    mp['l'] = 2;
    mp['z'] = 3;
    mp['x'] = 3;
    mp['c'] = 3;
    mp['v'] = 3;
    mp['b'] = 3;
    mp['n'] = 3;
    mp['m'] = 3;

    for (int i = 0; i < words.size(); i++)
    {
        int flag = 0;
        for (int j = 1; j < words[i].size(); j++)
        {
            if (mp[tolower(words[i][j])] != mp[tolower(words[i][j - 1])])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            ans.push_back(words[i]);
    }
    return ans;
}
int main()
{
    vector<string> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        words.push_back(s);
    }
    vector<string> ans = findWords(words);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}