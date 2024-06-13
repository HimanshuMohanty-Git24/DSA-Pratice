//Long Drive
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y;
        cin >> X >> Y;
        int h = ceil(10.0 * (Y - X) / (100 - Y));

        cout << h << endl;
    }
    return 0;
}
