//Count Inversions in an Array
#include<bits/stdc++.h>
using namespace std;
int ctr =0;
void Merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) { // Fixed the comparison
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            ctr += mid - left + 1; // Fixed this line
            right++; // Fixed this line
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void MergeSort(vector<int> &arr, int low, int high) {
    if (low == high) {
        return;
    }
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}
int numberOfInversions(vector<int>&a, int n) {
    MergeSort(a, 0, n - 1);
    return ctr;
}
int main()
{
    vector<int> a = {5, 3, 2, 1, 4};
    int n = a.size();
    cout << numberOfInversions(a, n);
   return 0;
}