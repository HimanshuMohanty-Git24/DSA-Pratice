#include <bits/stdc++.h>
using namespace std;
bool isPossible(int barrier, vector<int> arr, int n, int k)
{
    int studentctr = 1;
    int pageAllocated = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > barrier)
        {
            return false;
        }
        if (pageAllocated + arr[i] > barrier)
        {
            studentctr++;
            pageAllocated = pageAllocated + arr[i];
        }
        else
        {
            pageAllocated = pageAllocated + arr[i];
        }
    }
    if (studentctr > k)
    {
        return false;
    }
    return true;
}
int bookAlloc(vector<int> arr, int n, int k)
{
    int ans;
    int low = *min_element(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int high = sum;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (isPossible(mid, arr, n, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}
int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    cout << "Enter the numner of student" << endl;
    int k;
    cin >> k;
    int res = bookAlloc(arr, n, k);
    cout << "Max no of pages allocated is minimum:" << res;
    return 0;
}