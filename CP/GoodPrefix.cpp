//C. Good Prefixes
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int goodPrefixCount = 0;
        long long prefixSum = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += a[i];
            long long otherSum = prefixSum - a[i];
            if (otherSum == a[i]) {
                ++goodPrefixCount;
            }
        }

        cout << goodPrefixCount << '\n';
    }

    return 0;
}
