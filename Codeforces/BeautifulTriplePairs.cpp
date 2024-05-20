#include <bits/stdc++.h>
using namespace std;

int countBeautifulPairs(const vector<int>& a) {
    int n = a.size();
    int count = 0;

    // Generate all triples
    vector<array<int, 3>> triples;
    for (int j = 0; j <= n - 3; ++j) {
        triples.push_back({a[j], a[j + 1], a[j + 2]});
    }

    // Compare each pair of triples
    int m = triples.size();
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int diffCount = 0;
            if (triples[i][0] != triples[j][0]) ++diffCount;
            if (triples[i][1] != triples[j][1]) ++diffCount;
            if (triples[i][2] != triples[j][2]) ++diffCount;
            if (diffCount == 1) ++count;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << countBeautifulPairs(a) << '\n';
    }
    
    return 0;
}
