#include <bits/stdc++.h>
using namespace std;
void tripletsum(int arr[], int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[i] + arr[j] + arr[j + 1] == s)
            {
                cout << arr[i] << "," << arr[j] << "," << arr[j + 1] << endl;
                // arr[i] = INT_MIN;
                // arr[j] = INT_MIN;
                // arr[j + 1] = INT_MIN;
            }
        }
    }
}
int main()
{
    int arr[] = {1, 7, 9, 4, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum;
    cin >> sum;
    tripletsum(arr, size, sum);
    return 0;
}