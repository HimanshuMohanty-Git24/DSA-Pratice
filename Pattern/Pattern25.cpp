/*1234554321 Pattern 25
1234**4321
123****321
12******21
1********1*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;

    while (i <= n)
    {
        int Lctr = 1;
        int j = 1;
        while (j <= n - i + 1) // Left Counter part
        {
            cout << Lctr;
            Lctr++;
            j++;
        }
        int Lstar = i - 1;
        while (Lstar) // Left Star Part
        {
            cout << "*";
            Lstar--;
        }
        int Rstar = i - 1;
        while (Rstar) // Right Star Part
        {
            cout << "*";
            Rstar--;
        }
        int Rctr = n - i + 1;
        int k = 1;
        while (k <= n - i + 1)
        {
            cout << Rctr;
            Rctr--;
            k++;
        }

        cout << endl;
        i++;
    }

    return 0;
}