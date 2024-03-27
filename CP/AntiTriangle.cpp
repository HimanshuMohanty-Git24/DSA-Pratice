#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFormTriangle(int a, int b, int c) {
  // Check triangle inequality
  return (a + b > c) && (a + c > b) && (b + c > a);
}

vector<int> generateAntiTriangle(int N, int L) {
  vector<int> A(N);

  // Generate N distinct numbers between 1 and 10^9
  for (int i = 0; i < N; i++) {
    A[i] = i + 1;
  }

  // Sort the array
  sort(A.begin(), A.end());

  // Loop through all pairs and check triangle inequality with L
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (!canFormTriangle(A[i], A[j], L)) {
        // Swap elements to create an invalid combination
        swap(A[i], A[j]);
        return A;
      }
    }
  }

  // No valid combination found, should not happen with given constraints
  return vector<int>();
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N, L;
    cin >> N >> L;

    vector<int> A = generateAntiTriangle(N, L);

    if (A.empty()) {
      cout << "No solution possible" << endl;
    } else {
      for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
