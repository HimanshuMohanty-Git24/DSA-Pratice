#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}