#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapAlt(int arr[], int n)
{
    for (int i = 0; i < n - 1; i = i + 2)
    {
        swap(&arr[i], &arr[i + 1]);
    }
}
int main()
{
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    swapAlt(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}