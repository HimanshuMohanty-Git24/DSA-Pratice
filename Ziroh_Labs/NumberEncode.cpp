// #include<bits/stdc++.h>
//import those librraies thoes are nessray for the code
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string NumberEncoding(string str) {
    stringstream encodedStream; // stringstream to build the encoded string
    for (char& c : str) {
        if (isalpha(c)) {
            encodedStream << (tolower(c) - 'a' + 1); // Append the encoded letter position to the stringstream
        } else {
            encodedStream << c; // Append the non-alphabetic character to the stringstream
        }
    }
    return encodedStream.str(); // Convert stringstream to string and return
}

int main() {
    // Test cases
    cout << NumberEncoding("hello 45") << endl;  // Output: 85121215 45
    cout << NumberEncoding("jaj-a") << endl;     // Output: 10110-1
    return 0;
}
