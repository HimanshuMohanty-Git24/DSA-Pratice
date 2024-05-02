// 3110. Score of a String
#include <bits/stdc++.h>
using namespace std;
int scoreOfString(string s)
{
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        sum = sum + abs(s[i] - s[i + 1]);
    }
    return sum;
}
int main()
{
    string s;
    cin >> s;
    cout << scoreOfString(s) << endl;
    return 0;
}