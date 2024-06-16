//Spell Splice
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSpell(int N, const vector<pair<int, int>>& spells) {
    int max_strength = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int strength = spells[i].second * spells[j].first + spells[i].first * spells[j].second;
            max_strength = max(max_strength, strength);
        }
    }
    return max_strength;
}
//TC: O(N^2) SC: O(1)
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> spells(N);
        for (int i = 0; i < N; ++i) {
            cin >> spells[i].first >> spells[i].second; // Vi and Ai
        }
        cout << maxSpell(N, spells) << endl;
    }
    return 0;
}
