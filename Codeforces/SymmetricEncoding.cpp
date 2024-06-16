#include <bits/stdc++.h>
using namespace std;


string decodeString(const string &b) {

    set<char> uniqueChars(b.begin(), b.end());
    string r(uniqueChars.begin(), uniqueChars.end());


    unordered_map<char, char> decodeMap;
    int rLen = r.size();
    for (int i = 0; i < rLen; ++i) {
        decodeMap[r[i]] = r[rLen - 1 - i];
    }


    string s;
    s.reserve(b.size());
    for (char ch : b) {
        s.push_back(decodeMap[ch]);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string b;
        cin >> n >> b;
        cout << decodeString(b) << '\n';
    }

    return 0;
}
