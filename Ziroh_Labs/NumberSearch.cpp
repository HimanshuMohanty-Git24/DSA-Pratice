#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int NumberSearch(string str) {
    int sumtotalNum = 0;
    int totalLetter = 0;

    for (char c : str) {
        if (isdigit(c)) {
            sumtotalNum += c - '0';
        } else if (isalpha(c)) {
            totalLetter++;
        }
    }

    if (totalLetter == 0) {
        return 0;
    }
    printf("sumtotalNum: %d, totalLetter: %d\n", sumtotalNum, totalLetter);
    int result = round((double)sumtotalNum / totalLetter);
    return result;
}
int main()
{
    cout << NumberSearch("Hello6 9World 2, Nic8e D7ay!") << endl;
    cout << NumberSearch("H3ello9-9") << endl;
    cout << NumberSearch("One Number*1*") << endl;
    return 0;
}