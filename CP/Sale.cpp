//Sale
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
        }
        long long max = arr[0] * 2LL;
        long long sum = arr[0];
        for (int i = 1; i < n; i++) {
            long long val = static_cast<long long>(arr[i]);
            long long mul = val * 2LL;
            long long sum2 = sum + mul;
            if (sum2 > max)
                max = sum2;
            sum += val;
        }
        cout << max << endl;
        t--;
    }
    return 0;
}
