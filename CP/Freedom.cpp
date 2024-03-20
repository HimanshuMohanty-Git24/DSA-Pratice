#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isaArithmeticProgression(long long a, long long b, long long c) {
    return (2 * b == a + c);
}

void Freedom() {
    int n;
    cin >> n;
    vector<long long> arr(n); // Using vector for dynamic array size
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<long long, int> count;
    long long ctr = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            long long a = arr[i] - arr[j];
            long long b = arr[i] + arr[j];
            long long c = arr[i] * arr[j];
            if(isaArithmeticProgression(a, b, c)) {
                long long hash_val = a * 1000000000LL + b;
                ctr += count[hash_val];
            }
            count[b * 1000000000LL + c]++;
        }
    }
    cout << ctr << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        Freedom();
    }
    return 0;
}
