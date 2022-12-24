#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) // input
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j]) // check the element with each element
            {
                flag++; // if flag iterates more than 1 then the element is not unique
            }
        }
        if (flag == 1) // checks and prints
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}