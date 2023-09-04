// 27. Remove Element
#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return i;
}
int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    cout << endl
         << removeElement(nums, val);
    return 0;
}