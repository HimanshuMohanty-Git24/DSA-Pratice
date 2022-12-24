#include <bits/stdc++.h>
using namespace std;
int findDuplicate(int arr[], int n) // O(n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int hash[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < max + 1; i++)
    {
        if (hash[i] > 1)
        {
            return i;
        }
    }
    return 0;
}
// Aproach 2
int dup(int arr[], int n) // O(n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}
int main()
{
    int arr[] = {6, 3, 1, 5, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int dupe = findDuplicate(arr, n);
    int ans = dup(arr, n);
    cout << dupe << endl;
    cout << ans;

    return 0;
}