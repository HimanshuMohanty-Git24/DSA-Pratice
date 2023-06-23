/*1189. Maximum Number of Balloons
 */
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
using namespace std;

int maxNumberOfBalloons(string text)
{
    int b = 0, a = 0, l = 0, o = 0, n = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == 'b')
            b++;
        else if (text[i] == 'a')
            a++;
        else if (text[i] == 'l')
            l++;
        else if (text[i] == 'o')
            o++;
        else if (text[i] == 'n')
            n++;
    }
    int ans = 0;
    while (b >= 1 && a >= 1 && l >= 2 && o >= 2 && n >= 1)
    {
        ans++;
        b--;
        a--;
        l -= 2;
        o -= 2;
        n--;
    }
    return ans;
}
int main()
{
    string text = "loonbalxballpoon";
    cout << maxNumberOfBalloons(text);
    return 0;
}