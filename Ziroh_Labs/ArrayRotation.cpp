#include <iostream>
#include <string>
#include <vector>
using namespace std;
string ArrayRotation(const vector<int>& arr) {
    int r = arr[0];
    string result;

    for (int i = r; i < arr.size(); i++) {
        result += to_string(arr[i]);
    }

    for (int i = 0; i < r; i++) {
        result += to_string(arr[i]);
    }

    return result;
}//TC:O(n) where n is the size of the array
int main() {
    vector<int> arr1 = {3, 2, 1, 6};
    cout << "Input: 3,2,1,6" << endl;
    cout << "Output: " << ArrayRotation(arr1) << endl;

    vector<int> arr2 = {4, 3, 4, 3, 1, 2};
    cout << "Input: 4,3,4,3,1,2" << endl;
    cout << "Output: " << ArrayRotation(arr2) << endl;

    cout<<"Enter the array size: ";
    int n;
    cin>>n;
    vector<int> arr3(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr3[i];
    }
    cout << "Output: " << ArrayRotation(arr3) << endl;

    return 0;
}