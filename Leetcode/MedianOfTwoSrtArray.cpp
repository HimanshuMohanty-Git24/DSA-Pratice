/*4. Median of Two Sorted Arrays
 */
#include <bits/stdc++.h>
using namespace std;
double findMedian(vector<int> a, int n)
{
    if (n % 2 == 0)
    {
        return (a[n / 2] + a[n / 2 - 1]) / 2.0;
    }
    else
    {
        return a[n / 2];
    }
}
double findMedianSortedArrays(vector<int> nums1, vector<int> nums2)
{
    vector<int> res;
    res.insert(res.end(), nums1.begin(), nums1.end());
    res.insert(res.end(), nums2.begin(), nums2.end());
    sort(res.begin(), res.end());
    double ans = findMedian(res, res.size());
    return ans;
}
int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}