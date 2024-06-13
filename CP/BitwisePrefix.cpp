//Prefix Suffix Inequality
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        // Generate the array
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            A[i] = (i % 2 == 0) ? 3 : 6;
        }
        
        // Output the array
        for (int i = 0; i < N; ++i) {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
