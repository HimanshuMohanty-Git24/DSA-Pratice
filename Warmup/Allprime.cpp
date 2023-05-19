// print all prime number between 1 to N
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int count = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}