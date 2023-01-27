#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x)
{
    string num = to_string(x);
    int length = num.length();
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (num[i] != num[length - 1])
        {
            return false;
        }
        length--;
    }
    return true;
}
int main()
{
    int x = -121;
    if (isPalindrome(x))
    {
        cout << "It's a palindrome";
    }
    else
    {
        cout << "Not a palindrome";
    }

    return 0;
}