//Extreme Basketball
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int A, B;
        cin >> A >> B;

        int diff = A - B;
        int shots_needed = 0;

        if (diff >= 10) {
            // Alice already has a dominant victory
            shots_needed = 0;
        } else {
            int points_needed = 10 - diff;
            shots_needed = points_needed / 3;
            points_needed %= 3;
            shots_needed += (points_needed + 1) / 2;
        }

        cout << shots_needed << endl;
    }

    return 0;
}