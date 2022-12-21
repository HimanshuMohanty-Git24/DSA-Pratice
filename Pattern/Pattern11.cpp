/*A B C Pattern 10
A B C
A B C*/
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
        cout << endl;
        i++;
    }

    return 0;
}