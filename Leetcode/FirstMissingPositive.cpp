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
//other method:
int firstMissingPositive2(vector<int> nums)
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int max = nums[n-1];
    vector<int> mpp(max+1,0);

    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }

    for(int i=1;i<=max;i++){
        if(mpp[i]==0){
            return i;
        }
    }

    return nums[n-1]+1;
}

int main()
{
    vector<int> nums = {7,8,9,11,12};
    cout << firstMissingPositive2(nums);
    return 0;
}
