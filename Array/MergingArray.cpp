#include <bits/stdc++.h>
using namespace std;
void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
        {
            j++;
        }
    }
}
int main()
{
    int arr1[] = {1, 2, 2, 2, 3, 4};
    int arr2[] = {2, 2, 3, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1, arr2, n, m);
    return 0;
}