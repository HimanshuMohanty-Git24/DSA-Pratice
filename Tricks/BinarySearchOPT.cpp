#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int size, int key)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        int mid = i + ((j - i) / 2); // To not get problem withlarge position which are greater than 2^32
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            i = mid + 1;
        }
        else if (arr[mid] > key)
        {
            j = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 7, 9, 10, 24};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n;
    cin >> n;
    int index = BinarySearch(arr, size, n);
    if (index == -1)
    {
        cout << "Not Found";
    }
    else
    {
        cout << n << " Found at:" << index << " Position";
    }
    return 0;
}