/*448. Find All Numbers Disappeared in an Array*/
#include <bits/stdc++.h>
using namespace std;
vector<int> findDisappearedNumbers(vector<int> nums)
{
    vector<int> res;                // Create a vector array for storing the result
    sort(nums.begin(), nums.end()); // sortthe exting array
    int n = nums.size();            // store  the size of the nums array
    for (int i = 1; i <= n; i++)    // itterate through 1-n anch check if it exists or not
    {
        if (binary_search(nums.begin(), nums.end(), i)) // if exists continue
        {
            continue;
        }
        else
        {
            res.push_back(i); // push to the res array
        }
    }
    return res; // return res
}
int main()
{
    vector<int> nums = {1, 1};
    vector<int> res = findDisappearedNumbers(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}