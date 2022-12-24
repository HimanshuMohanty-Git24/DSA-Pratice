#include <bits/stdc++.h>
using namespace std;
int findUnique(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i]; // XOR with all ement will give the only unique element
    }
    return ans;
}
int main()
{
    int arr[] = {2, 3, 1, 6, 3, 6, 2};
    int res = findUnique(arr, 7);
    cout << res;
    return 0;
}