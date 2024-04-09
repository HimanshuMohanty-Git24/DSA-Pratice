//Superincreasing
#include <iostream>
#include <cmath>

#define MAX_N 200005
#define MOD 1000000007

long long int m[MAX_N];
long long int m2[MAX_N];
long long int dist[MAX_N];

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, x;
        std::cin >> n >> k >> x;
        k--;

        if (k >= 30) {
            std::cout << "NO\n";
            continue;
        }

        long long int minval = std::pow(2, k);

        if (x >= minval) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
