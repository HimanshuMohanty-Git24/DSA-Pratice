//B. Maximum Multiple Sum
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxSum = 0;
        int maxMul = 2;

        for (int x = 2; x <= n; ++x) {
            int sum = 0;
            for (int k = 1; x * k <= n; ++k) {
                sum += x * k;
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxMul = x;
            }
        }
        cout << maxMul << endl;
    }
    return 0;
}
