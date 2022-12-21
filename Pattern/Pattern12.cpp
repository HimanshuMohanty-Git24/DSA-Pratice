/*A B C Pattern 12
B C D
C D E*/
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
            ch++;
            j++;
        }
        ch = ch - 2; // to get to the second char
        cout << endl;
        i++;
    }

    return 0;
}