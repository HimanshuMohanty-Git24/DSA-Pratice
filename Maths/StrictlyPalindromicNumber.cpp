// 2396. Strictly Palindromic Number
#include <bits/stdc++.h>
using namespace std;
bool isStrictlyPalindromic(int n)
{
    int lb = 2;
    int ub = n - 2;
}
int main()
{
    int n;
    cin >> n;
    if (isStrictlyPalindromic(n))
        cout << "True";
    else
        cout << "False";
    return 0;
}