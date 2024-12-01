#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    vector<int> arr(2);
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1')
        {
            arr[0]++;
        }
        if (s2[i] == '1')
        {
            arr[1]++;
        }
    }

    // if nuber of 1&0 is dvible by 2 then that menas we can rearrange the string and make it equal
    if ((arr[0] + arr[1]) % 2 == 0 && arr[0] % 2 == 0 && arr[1] % 2 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}