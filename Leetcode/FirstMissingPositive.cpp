/*41. First Missing Positive
 */
#include <bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int i = 1;
    int n = nums.back();
    for (; i <= n; i++)
    {
        if (binary_search(nums.begin(), nums.end(), i))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    if (i == n)
    {
        return i + 1;
    }
    else
    {
        return i;
    }
}
int main()
{
    vector<int> nums = {7, 8, 9, 11, 12};
    cout << firstMissingPositive(nums);
    return 0;
}