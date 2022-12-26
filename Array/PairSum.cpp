#include <bits/stdc++.h>
using namespace std;
void pairsum(int arr[], int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                cout << arr[i] << "," << arr[j] << endl;
                arr[i] = INT_MIN;
                arr[j] = INT_MIN;
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
    pairsum(arr, size, sum);
    return 0;
}