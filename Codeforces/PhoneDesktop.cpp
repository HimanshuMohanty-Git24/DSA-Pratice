#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;


        int screens_for_y = (y + 1) / 2;


        int used_cells_by_y = y * 4;
        int remaining_cells = max(0, screens_for_y * 15 - used_cells_by_y);


        int remaining_x = x - remaining_cells;
        int screens_for_x = max(0, (remaining_x + 14) / 15);


        int total_screens = screens_for_y + screens_for_x;


        cout << total_screens << endl;
    }
    return 0;
}
