//Permutation Disturbance
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--; // Adjusting array values to zero-based indexing
        }

        int start = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == i) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                ans++;
            }
        }

        if (arr[n - 1] == n - 1) // Checking if the last element is correctly placed
            ans++;

        cout << ans << endl;
        t--;
    }

    return 0;
}

