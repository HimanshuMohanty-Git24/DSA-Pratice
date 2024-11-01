//Distribute Cookies
#include <bits/stdc++.h>
using namespace std;

int cookieTime(int N, int M) {
    if (M % N == 0) {
        return 0;
    }
    if (M < N) {
        return N - M;
    }
    int remainder = M % N;
    return min(remainder, N - remainder);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        cout << cookieTime(N, M) << endl;
    }
    return 0;
}
