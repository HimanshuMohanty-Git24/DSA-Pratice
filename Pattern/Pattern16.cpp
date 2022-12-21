/*D Pattern 16
C D
B C D
A B C D*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        char ch = 'A';
        ch = ch + n - i; // To get the specific starting alphabate
        int j = 1;
        while (j <= i)
        {
            cout << ch << " ";
            ch++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}