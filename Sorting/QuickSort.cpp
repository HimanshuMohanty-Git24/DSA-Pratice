#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int Partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i =low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot&&i<high){
            i++;
        }
        while(arr[j]>pivot&&j>low){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void QuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int PartitionIndex = Partition(arr, low, high);
        QuickSort(arr, low, PartitionIndex-1);
        QuickSort(arr, PartitionIndex + 1, high);
    }
}
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int size = arr.size();
    QuickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
