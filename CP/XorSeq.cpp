//Earning on Bets
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


long long lcm(vector<long long>& multipliers) {
    long long lcm_value = multipliers[0];
    for (int i = 1; i < multipliers.size(); i++) {
        lcm_value = (lcm_value * multipliers[i]) / gcd(lcm_value, multipliers[i]);
    }
    return lcm_value;
}


void solveEarningOnBets(int num_outcomes, vector<long long>& multipliers) {
    long long lcm_value = lcm(multipliers);
    long long total_bets = accumulate(multipliers.begin(), multipliers.end(), 0LL, [&](long long sum, long long multiplier) {
        return sum + lcm_value / multiplier;
    });

    if (total_bets >= lcm_value) {
        cout << "-1" << endl;
        return;
    }

    for (long long multiplier : multipliers) {
        cout << lcm_value / multiplier << " ";
    }
    cout << endl;
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int num_outcomes;
        cin >> num_outcomes;

        vector<long long> multipliers(num_outcomes);
        for (long long& multiplier : multipliers) {
            cin >> multiplier;
        }

        solveEarningOnBets(num_outcomes, multipliers);
    }

    return 0;
}