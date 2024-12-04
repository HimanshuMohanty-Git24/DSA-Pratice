//2825. Make String a Subsequence Using Cyclic Increments
#include<bits/stdc++.h>
using namespace std;
bool canMakeSubsequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    if (n < m) return false;
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        char incrementedChar = (str1[i] - 'a' + 1) % 26 + 'a';
        if (str1[i] == str2[j] || incrementedChar == str2[j]) {
            j++;
        }
        i++;
    }
        
    return j == m;
}
int main()
{
    string str1 = "abc";
    string str2 = "ad";
    cout<<canMakeSubsequence(str1, str2);
   return 0;
}