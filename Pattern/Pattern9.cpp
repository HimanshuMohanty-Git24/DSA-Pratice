/*A A A A A Pattern 9
B B B B B
C C C C C
D D D D D
E E E E E*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    char ch = 'A';
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout << ch << " ";
            j++;
        }
        ch = ch + 1;
        cout << endl;
        i++;
    }
    return 0;
}