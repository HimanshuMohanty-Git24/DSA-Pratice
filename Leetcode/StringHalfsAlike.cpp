// 1704. Determine if String Halves Are Alike
#include <bits/stdc++.h>
using namespace std;
bool halvesAreAlike(string s)
{
    int n = s.size();
    int volctr1 = 0;
    int volctr2 = 0;
    for (int i = 0; i < (n / 2); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
            s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
            s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
            s[i] == 'U')
        {
            volctr1++;
        }
    }
    for (int i = (n / 2); i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
            s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
            s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
            s[i] == 'U')
        {
            volctr2++;
        }
    }
    if (volctr1 == volctr2)
    {
        return true;
    }
    else
    {
        return false;
    }
} // Time complexity: O(n) Space complexity: O(1)
int main()
{
    cout << halvesAreAlike("textbook");
    return 0;
}