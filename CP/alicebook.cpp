#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, lastEle;
        cin >> n;

        vector<int> arr(n - 1);
        for (int j = 0; j < n - 1; j++)
        {
            cin >> arr[j];
        }

        cin >> lastEle;
        sort(arr.begin(), arr.end());

        cout << arr[n - 2] + lastEle << endl;
    }

    return 0;
}