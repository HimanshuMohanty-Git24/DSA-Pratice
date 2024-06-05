#include <bits/stdc++.h>
using namespace std;

vector<int> build_segment_tree(vector<int>& arr, int neutral) {
    int n = arr.size();
    vector<int> tree(4 * n, neutral);

    function<void(int, int, int)> build = [&](int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    };

    build(1, 0, n - 1);
    return tree;
}

int query(vector<int>& tree, int l, int r, int node, int start, int end, int neutral) {
    if (r < start || end < l) {
        return neutral;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int left = query(tree, l, r, 2 * node, start, mid, neutral);
    int right = query(tree, l, r, 2 * node + 1, mid + 1, end, neutral);
    return max(left, right);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = a[i] - b[i];
        }

        vector<int> diff_tree = build_segment_tree(diff, 0);
        vector<int> sum_tree = build_segment_tree(a, 0);

        bool canWin = false;
        for (int i = 0; i < n; ++i) {
            int gone_till = upper_bound(b.begin(), b.end(), b[i] + 2 * k) - b.begin() - 1;
            int worst = 0;
            if (i > 0) worst = max(worst, query(diff_tree, 0, i - 1, 1, 0, n - 1, 0));
            if (gone_till != n - 1) {
                worst = max(worst, query(diff_tree, gone_till + 1, n - 1, 1, 0, n - 1, 0) -
                                   query(sum_tree, i, gone_till, 1, 0, n - 1, 0));
            }
            if (worst == 0) {
                canWin = true;
                break;
            }
        }

        cout << (canWin ? "YES" : "NO") << endl;
    }

    return 0;
}