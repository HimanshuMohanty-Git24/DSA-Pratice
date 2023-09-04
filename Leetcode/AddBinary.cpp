// 67. Add Binary
#include <bits/stdc++.h>
using namespace std;
string addBinary(string A, string B)
{
    // This is used to add the leading 000 so that both the stribg are equal size
    if (A.length() > B.length())
        return addBinary(B, A); // if alenth is > b length change the positinon of A ansd B

    int diff = B.length() - A.length();
    // Make a padding string add the leading Zeros
    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');
    // Addin the leading zeros to make the string equal length
    A = padding + A;
    string res;
    char carry = '0';

    for (int i = A.length() - 1; i >= 0; i--)
    {

        if (A[i] == '1' && B[i] == '1')
        {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }

        else if (A[i] == '0' && B[i] == '0')
        {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }
        else if (A[i] != B[i])
        {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }
    if (carry == '1')
        res.push_back(carry);
    reverse(res.begin(), res.end()); // Reversing the string a sthe answer we used PushBack function
    // Removing Leading Zeros
    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    return (res.substr(index)); // Returning the string to using the substring function
}
int main()
{
    string a = "11", b = "1";
    cout << addBinary(a, b);
    return 0;
}