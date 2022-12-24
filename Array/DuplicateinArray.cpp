#include <bits/stdc++.h>
using namespace std;
void findDuplicate(int arr[], int n) // O(n)
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
            cout << i << " ";
        }
    }
}
int main()
{
    int arr[] = {6, 3, 1, 5, 4, 3, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    findDuplicate(arr, n);

    return 0;
}