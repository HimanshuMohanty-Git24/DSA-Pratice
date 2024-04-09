#include <iostream>
#include <vector>

using namespace std;

vector<int> countBuses(vector<int>& arr, int n) {
    arr.insert(arr.begin(), -1);

    for (int i = 1; i <= n; ++i) {
        for (int j = i * 2; j <= n; j += i) {
            arr[j] -= arr[i];
        }
    }

    return vector<int>(arr.begin() + 1, arr.end());
}

int main() {
    vector<int> buses1 = {1, 2, 3};
    vector<int> result1 = countBuses(buses1, 3);
    cout << "Test Case 1 Output: ";
    for (int bus : result1) {
        cout << bus << " ";
    }
    cout << endl;

    vector<int> buses2 = {2, 3, 4, 6};
    vector<int> result2 = countBuses(buses2, 4);
    cout << "Test Case 2 Output: ";
    for (int bus : result2) {
        cout << bus << " ";
    }
    cout << endl;

    return 0;
}
