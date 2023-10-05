// 2396. Strictly Palindromic Number
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s){
    int n = s.length();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
bool isStrictlyPalindromic(int n)
{
    int lb = 2;
    int ub = n - 2;
    for(int i=lb;i<=ub;i++){
        string s = "";
        int temp = n;
        while(temp){
            s += (temp%i);
            temp /= i;
        }
        if(!isPalindrome(s))
            return false;
    }
    return true;
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