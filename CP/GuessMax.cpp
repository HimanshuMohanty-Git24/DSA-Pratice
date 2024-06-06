//Guess the Maximum
#include<bits/stdc++.h>
using namespace std;

int getMaxK(vector<int> &arr, int n) {
    int minval = INT_MAX;
    for(int i = 0; i < n - 1; i++) {
        int maxval = max(arr[i], arr[i + 1]);
        minval = min(minval, maxval);
    }
    return minval - 1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << getMaxK(arr, n) << endl;
    }
    return 0;
}
