#include <iostream>
#include <string>
using namespace std;

// Function to check if a substring can be reversed to form a k-proper string
bool isValidSubstring(string& s, int start, int k) {
    for (int i = start; i < s.length(); i += k) {
        char target = s[i];
        for (int j = i; j < min((int)s.length(), i + k); j++) {
            if (s[j] != target) return false;
        }
    }
    return true;
}

int findP(string& s, int n, int k) {
    for (int i = 1; i <= k; i++) {
        if (isValidSubstring(s, i - 1, k)) return n - i + 1;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int p = findP(s, n, k);
        cout << p << endl;
    }

    return 0;
}
