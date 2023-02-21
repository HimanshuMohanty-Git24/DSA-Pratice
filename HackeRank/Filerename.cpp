#include <bits/stdc++.h>
using namespace std;
/*
 * Complete the 'renameFile' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING newName
 *  2. STRING oldName
 */

int renameFile(string newName, string s)
{
    int n = s.length();
    int ctr = 0;
    int subSetct = (1 << n);
    for (int mask = 0; mask < subSetct; mask++)
    {
        string sub = "";
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                sub += s[i];
            }
        }
        if (sub == newName)
        {
            ctr++;
        }
    }
    return ctr % 1000000007;
}
int main()
{
    cout << renameFile("aba", "ababa");

    return 0;
}