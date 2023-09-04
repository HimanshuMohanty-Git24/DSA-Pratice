#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int size = arr.size();
    MergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
