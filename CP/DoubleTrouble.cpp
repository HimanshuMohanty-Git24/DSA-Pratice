//Double Trouble
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define read(a) for (auto &i: a) cin >> i

bool canActivateAllBalls(const vi &a, const vi &p) {
    int n = a.size();
    int cnt = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] + p[i] < a[i + 1]) {
            ++cnt;
        }
    }
    if (cnt <= 2) return true;

    cnt = 1;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] - p[i] > a[i - 1]) {
            ++cnt;
        }
    }
    if (cnt <= 2) return true;

    int leftReach = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] + p[i] >= a[i + 1]) {
            leftReach = i + 1;
        } else {
            break;
        }
    }
    int rightReach = n - 1;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] - p[i] <= a[i - 1]) {
            rightReach = i - 1;
        } else {
            break;
        }
    }
    if (leftReach + 1 >= rightReach) return true;

    for (int i = 1; i < n; ++i) {
        if (a[i] - p[i] > a[i - 1]) {
            for (int j = i; j < n - 1; ++j) {
                if (a[j] + p[j] < a[j + 1]) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n), p(n);
        read(a);
        read(p);
        if (canActivateAllBalls(a, p)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
