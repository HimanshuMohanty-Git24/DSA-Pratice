// 12. Integer to Roman
#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num)
{
    string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string thousands = M[num / 1000];
    string hundreds = C[(num % 1000) / 100];
    string tens = X[(num % 100) / 10];
    string ones = I[num % 10];
    string ans = thousands + hundreds + tens + ones;
    return ans;
} // Time Complexity: O(1) as there is a finite set of roman numerals, and given number is always less than 3999.
int main()
{
    int num;
    cin >> num;
    cout << intToRoman(num) << endl;
    return 0;
}