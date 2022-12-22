/*1234 Pattern 22
 234
  34
   4*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int num;
    while (i <= n)
    {
        num = i;
        int space = i - 1;
        while (space)
        {
            cout << " ";
            space--;
        }
        int j = 1;
        while (j <= n - i + 1)
        {
            cout << num;
            num++;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}