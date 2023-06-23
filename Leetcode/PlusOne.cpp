/*66. Plus One
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] == 9) // if 9 or  99 or 999 ..... then make it 0
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }
    digits[0] = 1;       // if 9999 then make it 10000 etc.
    digits.push_back(0); // if 9999 then make it 10000 etc.
    return digits;
}
int main()
{
    vector<int> digits = {9};
    vector<int> ans = plusOne(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}