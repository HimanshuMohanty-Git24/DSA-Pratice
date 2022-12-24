#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 6;
    int arr[n] = {1, 1, 8, 3, 4, 5, 3, 6, 7};
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                flag++;
            }
        }
        if (flag == 0)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}