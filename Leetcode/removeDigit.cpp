// 2259. Remove Digit From Number to Maximize Result
#include <bits/stdc++.h>
using namespace std;
string removeDigit(string number, char digit)
{
    int count = 0, iter = 1;
    ;
    int s[number.size()];
    for (int i = 0; i < number.length(); ++i)
    {
        if (number[i] == digit)
        {
            count++;
        }
    }
    for (int i = 0; i < number.length(); ++i)
    {
        if (number[i] == digit && iter == count)
        {
            number.erase(number.begin() + i);
            break;
        }
        else if (number[i] == digit && iter != count)
        {
            if (number[i + 1] > number[i])
            {
                number.erase(number.begin() + i);
                break;
            }
            else
            {
                iter++;
                continue;
            }
        }
    }
    return number;
}

int main()
{
    string number = "133235";
    char digit = '3';
    cout << removeDigit(number, digit) << endl;
    number = "12345";
    digit = '1';
    cout << removeDigit(number, digit) << endl;
    number = "1231";
    digit = '1';
    cout << removeDigit(number, digit) << endl;
    number = "551";
    digit = '5';
    cout << removeDigit(number, digit) << endl;
    number = "2998589353917872714814599237991174513476623756395992135212546127959342974628712329595771672911914471";
    digit = '3';
    cout << removeDigit(number, digit) << endl;

    return 0;
}