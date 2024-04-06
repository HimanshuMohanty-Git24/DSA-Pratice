// N bowls
#include<bits/stdc++.h>
using namespace std;

int find_modified_bowl(int N, vector<int>& marbles) {
    for (int i = N - 1; i >= 0; --i) {
        if (marbles[i] < 9) {
            marbles[i]++;
            if (i < N - 1) {
                marbles[N - 1] = 0;
            }
            return i;
        }
        else if (marbles[i] == 9) {
            if (i > 0) {
                marbles[i - 1]++;
                marbles[i] = 0;
            }
            else {
                marbles[i] = 0;
            }
        }
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<int> marbles(N);
    for (int i = 0; i < N; ++i) {
        cin >> marbles[i];
    }
    int modified_bowl = find_modified_bowl(N, marbles);
    cout << modified_bowl << endl;

    return 0;
}