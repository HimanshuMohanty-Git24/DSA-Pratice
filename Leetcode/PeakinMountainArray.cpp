#include <bits/stdc++.h>
using namespace std;
int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    int j = n - 1;
    int mid;
    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (mid != 0 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) // pe-1<peak elemen>pe+1
        {
            return arr[mid];
        }
        else if (arr[mid] < arr[mid + 1]) // if the current mid element is smaller than than its next element we move the low pointer mid+1 simillar to BS
        {
            i = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1]) // if the current mid element is greater than than its next element we move the higher pointer mid-1 simillar to BS
        {
            j = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {3, 5, 3, 2, 0};
    int ans = peakIndexInMountainArray(arr);
    cout << ans << endl;
    return 0;
}