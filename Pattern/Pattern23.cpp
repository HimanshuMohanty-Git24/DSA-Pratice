/*  1 Pattern 23
 23
456*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int val = 1;
    while (i <= n)
    {
        int space = n - i;
        while (space)
        {
            cout << " ";
            space--;
        }
        int j = 1;
        while (j <= i)
        {
            cout << val;
            val++;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}