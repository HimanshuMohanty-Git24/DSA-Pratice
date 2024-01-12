// 171. Excel Sheet Column Number
#include <bits/stdc++.h>
using namespace std;
int titleToNumber(string columnTitle)
{
    // Reverse the string
    reverse(columnTitle.begin(), columnTitle.end());
    int columnNumber = 0;
    for (int i = 0; i < columnTitle.size(); i++)
    {

        // Subtracting 64 because A is 65 in ASCII
        columnNumber += (columnTitle[i] - 64) * pow(26, i);
    }
    return columnNumber;
}
int main()
{
    string columnTitle;
    cin >> columnTitle;
    cout << titleToNumber(columnTitle) << endl;
    return 0;
}