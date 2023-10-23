//1. Two Sum
#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}//Time complexity: O(n^2) Space complexity: O(1)
//More efficient solution
vector<int> twoSum1(vector<int> &nums, int target)
{
    map<int, int> m;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        int more = target - a;
        if (m.find(more) != m.end())
        {
            res.push_back(m[more]);
            res.push_back(i);
            return res;
        }
        m[a] = i;
    }
    return res;
}//Time complexity: O(n) Space complexity: O(n)
//Most Optimal solution
vector<int> twoSum2(vector<int> &nums,int target){
    
}
int main()
{
    vector<int> arr = {3,2,4};
    int target=6;
    vector<int> res = twoSum(arr, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout<<endl;
    vector<int> res1 = twoSum1(arr, target);
    for (int i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << " ";
    }

    return 0;
}