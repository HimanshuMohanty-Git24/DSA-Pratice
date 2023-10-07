// 1323. Maximum 69 Number
#include <bits/stdc++.h>
using namespace std;
int maximum69Number(int num)
{
    string s = to_string(num);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '6')
        {
            s[i] = '9';
            break;
        }
    }
    return stoi(s);
}
int main()
{
    int n; // 9669
    cin >> n;
    cout << maximum69Number(n); // 9969
    // We acn flip only one digit at a time either 6 to 9 or 9 to 6
    return 0;
}