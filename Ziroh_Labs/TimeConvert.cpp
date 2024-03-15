#include <iostream>
#include <string>
using namespace std;
string TimeConvert(int num) {
    return to_string(num/60)+":"+to_string(num%60);
}
int main() {
    cout << TimeConvert(126) << endl; // Output: 2:6
    cout << TimeConvert(45) << endl;  // Output: 0:45
    return 0;
}