#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int filledOrders(vector<int> orders, int k) {
    sort(orders.begin(), orders.end()); // sort orders in ascending order
    int count = 0;
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i] <= k) { // if order can be fulfilled
            k -= orders[i]; // subtract from available widgets
            count++; // increment order count
        } else {
            break; // exit loop if order cannot be fulfilled
        }
    }
    return count;
}

int main() {
    vector<int> orders = {10, 30};
    int k = 40;
    cout << filledOrders(orders, k) << endl; // output: 2
    return 0;
}
