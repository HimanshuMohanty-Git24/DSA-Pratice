#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int brahma, vishnu, shiva;
        cin >> brahma >> vishnu >> shiva;
        if (shiva < vishnu)
        {
            cout << brahma * vishnu << endl;
        }
        else
        {
            int ganesh = min(brahma, shiva - vishnu);
            int lakshmi = brahma - ganesh;
            int durga = shiva - ganesh;
            int ans = lakshmi * vishnu + (shiva * (shiva + 1) / 2) - (durga * (durga + 1) / 2);
            cout << ans << endl;
        }
    }
    return 0;
}
