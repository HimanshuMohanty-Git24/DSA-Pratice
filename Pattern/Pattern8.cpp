/*1 Pattern 8
2 1
3 2 1
4 3 2 1*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int count = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << i - j + 1 << " "; // Logic
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}