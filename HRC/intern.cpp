#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int id;
    cin >> id;

    if (id % 5000 == 0) {
        int intern = id / 5000;
        if (intern == 1) {
            cout << "First Intern [Day " << id % 5000 << "]" << endl;
        } else if (intern == 2) {
            cout << "Second Intern [Day " << id % 5000 << "]" << endl;
        } else if (intern == 3) {
            cout << "Third Intern [Day " << id % 5000 << "]" << endl;
        }
    } else {
        int x = id % 100;
        int root = (-1 + sqrt(1 + 8 * x)) / 2;
        int idn = id - root * 5000;
        idn = idn - root;
        int intern = idn / 5000;
        if (intern == 1) {
            cout << "First Intern [Day " << root + 1 << "]" << endl;
        } else if (intern == 2) {
            cout << "Second Intern [Day " << root + 1 << "]" << endl;
        } else if (intern == 3) {
            cout << "Third Intern [Day " << root + 1 << "]" << endl;
        }
    }

    return 0;
}
