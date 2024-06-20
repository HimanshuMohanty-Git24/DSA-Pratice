// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define F first
#define S second
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define SZ(a) (int)(a.size())
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL)
#define deb(a) cerr << #a << " = " << (a) << endl;
#define deb1(a)                                                                \
    cerr << #a << " = [ ";                                                     \
    for (auto it = a.begin(); it != a.end(); it++)                             \
        cerr << *it << " ";                                                    \
    cerr << "]\n";
#define endl "\n"
const long long mod = 1e9 + 7;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    FOR(i, 0, n) { cin >> a.at(i); }
    VI bad(n, 0);
    bad[0] = 1;
    auto check = [&]() {
        int prod = 0;
        FOR(i, 0, n) {
            if (bad[i] == 0)
                continue;
            FOR(j, 0, n) {
                if (bad[j] == 0)
                    prod += a[i] * a[j];
            }
        }
        if (prod <= c)
            return true;
        return false;
    };
    if (check())
        cout << 1 << endl;
    else {
        int sz = 1;
        while (sz < n) {
            int mi = -1;
            FOR(i, 0, n) {
                if (bad[i] == 0 && (mi == -1 || a[i] > a[mi]))
                    mi = i;
            }
            bad[mi] = 1;
            sz++;
            if (check()) {
                cout << sz << endl;
                return;
            }
        }
    }
}

signed main() {
    fast_io;
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int totalTests = 1;
    cin >> totalTests;
    for (int testNo = 1; testNo <= totalTests; testNo++) {
        // cout << "Case #" << testNo << ": ";
        solve();
    }
    return 0;
}