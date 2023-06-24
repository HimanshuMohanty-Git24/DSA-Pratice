/*268. Missing Number
 */
#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    cout << n << endl;
    int i = 0;
    for (; i <= n; i++)
    {
        if (binary_search(nums.begin(), nums.end(), i))
        {
            cout << i << "if" << endl;
            continue;
        }
        else
        {
            cout << i << "else" << endl;
            break;
        }
    }
    if (i == n)
    {
        return n;
    }
    else
    {
        return i;
    }
}
int main()
{
    vector<int> nums = {3, 0, 1};
    cout << missingNumber(nums);
    return 0;
}