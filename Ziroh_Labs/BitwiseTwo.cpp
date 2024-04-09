#include <iostream>
#include <string>
using namespace std;

string BitwiseTwo(string strArr[], int arrLength) {
    string result = "";
    for (size_t i = 0; i < strArr[0].length(); ++i) {
        if (strArr[0][i] == '1' && strArr[1][i] == '1') {
            result += '1';
        } else {
            result += '0';
        }
    }
    return result;
}

int main(void) {
    string arr[] = { "1101", "1000" };
    string ans=BitwiseTwo(arr, 2); // Output: 1000
    cout<<ans;
    return 0;
}
