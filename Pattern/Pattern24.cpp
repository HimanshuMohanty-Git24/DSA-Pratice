/*1
        121 Pattern 24
       12321
      1234321
     123454321
    12345654321
   1234567654321
  123456787654321
 12345678987654321
12345678910987654321*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int Lval;
    int Rval = 1;
    while (i <= n)
    {
        Lval = 1;
        Rval = i - 1;
        int space = n - i;
        while (space)
        {
            cout << " ";
            space--;
        }
        int j = 1;
        while (j <= i)
        {
            cout << Lval;
            Lval++;
            j++;
        }
        int k = 1;
        while (k <= i - 1)
        {
            cout << Rval;
            Rval--;
            k++;
        }
        cout << endl;
        i++;
    }

    return 0;
}