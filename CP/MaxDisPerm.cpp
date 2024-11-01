//Maximum Distance Permutations
#include <bits/stdc++.h>
using namespace std;

void maxDisPerm(int N) {
    vector<int> A(N), B(N);

    for (int i = 0; i < N; ++i) {
        A[i] = i + 1;  // A is [1, 2, ..., N]
    }

    if (N % 2 == 0) {
        for (int i = 0; i < N; ++i) {
            B[i] = N - i;  // B is [N, N-1, ..., 1]
        }
    } else {
        // Cyclic shift for odd N
        for (int i = 0; i < N; ++i) {
            B[i] = (i + (N / 2 + 1)) % N + 1;
        }
    }

    // Print permutation A
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Print permutation B
    for (int i = 0; i < N; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        maxDisPerm(N);
    }
    return 0;
}



