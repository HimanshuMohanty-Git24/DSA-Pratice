// sort elements in arry by frequency of element
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
    map<int, int> freq;
    for (int i = 0; i < n; i++) // Count the frequency of each element
    {
        freq[arr[i]]++;
    }
    // easy logic

    sort(arr.begin(), arr.end(), [&](int a, int b)
         {
        if (freq[a] == freq[b])
        {
            return a < b;
        }
        return freq[a] > freq[b]; });
}