// 989. Add to Array-Form of Integer
#include <bits/stdc++.h>
using namespace std;
vector<int> addToArrayForm(vector<int> num, int k)
{
    vector<int> ans;
    int i = num.size() - 1; // Start from the least significant digit of num
    int carry = 0;

    while (i >= 0 || k > 0 || carry > 0)
    {
        int digit = carry;

        if (i >= 0)
        {
            digit += num[i];
            i--;
        }

        if (k > 0)
        {
            digit += k % 10;
            k /= 10;
        }

        ans.push_back(digit % 10);
        carry = digit / 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    vector<int> num = {1, 2, 6, 3, 0, 7, 1, 7, 1, 9, 7, 5, 6, 6, 4, 4, 0, 0, 6, 3};
    int k = 516;
    vector<int> ans = addToArrayForm(num, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}