#include <iostream>
#include <vector>

using namespace std;

int countLitAreas(vector<vector<int>>& streetLights) {
    int totalLength = 0;

    for (int i = 0; i < streetLights.size(); ++i) {
        totalLength += streetLights[i][1] - streetLights[i][0];
        // Subtract the overlapping portion with the next street light if it exists
        if (i < streetLights.size() - 1 && streetLights[i][1] > streetLights[i + 1][0]) {
            totalLength -= streetLights[i][1] - streetLights[i + 1][0];
        }
    }

    return totalLength;
}

int main() {
    // Test Case 1
    vector<vector<int>> streetLights1 = {{5, 8}, {10, 12}};
    cout << "Test Case 1 Output: " << countLitAreas(streetLights1) << endl;

    // Test Case 2
    vector<vector<int>> streetLights2 = {{5, 10}, {8, 12}};
    cout << "Test Case 2 Output: " << countLitAreas(streetLights2) << endl;

    return 0;
}
