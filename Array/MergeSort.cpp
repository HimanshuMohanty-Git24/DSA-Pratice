#include <bits/stdc++.h>
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void merge(int nums1[], int m, int nums2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
    printArr(nums1, m + n);
    for (int i = 0; i < n + m - 1; i++)
    {
        for (int j = 0; j < n + m - i - 1; j++)
        {
            if (nums1[j] > nums1[j + 1])
            {
                int temp = nums1[j];
                nums1[j] = nums1[j + 1];
                nums1[j + 1] = temp;
            }
        }
    }
    cout << endl;
    printArr(nums1, m + n);
}

int main()
{
    int nums1[] = {2, 5, 6, 0, 0, 0};
    int nums2[] = {1, 3, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int n = sizeof(nums2) / sizeof(nums2[0]);
    int m = 0;
    for (int i = 0; i < size1; i++)
    {
        if (nums1[i] != 0)
        {
            m++;
        }
    }
    cout << m << endl;
    merge(nums1, m, nums2, n);
    return 0;
}
// Output:
//[1,2,3,4,5,6]