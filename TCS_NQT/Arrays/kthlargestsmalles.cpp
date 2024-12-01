#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    sort(arr.begin(), arr.end());

    cout << k << "th smallest element is: " << arr[k - 1] << endl;
    cout << k << "th largest element is: " << arr[n - k] << endl;
}