//Large Differences
#include <bits/stdc++.h>
using namespace std;
//TC: O(n) SC: O(1)
int calculateAdjacentDifferenceSum(vector<int>& arr) {
    int n = arr.size();
    int adjSubSum = 0;
    for (int i = 0; i < n - 1; i++) {
        adjSubSum += abs(arr[i] - arr[i + 1]);
    }
    return adjSubSum;
}

int maxPossibleAdjacentDifferenceSum(vector<int>& arr, int k) {
    int n = arr.size();
    int initialSum = calculateAdjacentDifferenceSum(arr);
    int maxSum = initialSum;

    for (int i = 0; i < n; i++) {
        int original = arr[i];

        // Try changing arr[i] to 1
        arr[i] = 1;
        int sum1 = calculateAdjacentDifferenceSum(arr);
        maxSum = max(maxSum, sum1);

        // Try changing arr[i] to K
        arr[i] = k;
        int sum2 = calculateAdjacentDifferenceSum(arr);
        maxSum = max(maxSum, sum2);

        // Restore the original value
        arr[i] = original;
    }

    return maxSum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << maxPossibleAdjacentDifferenceSum(arr, k) << endl;
    }
    return 0;
}
