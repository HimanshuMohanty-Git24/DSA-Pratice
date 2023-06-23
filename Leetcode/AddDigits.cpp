/*258. Add Digits
 */
/*38-->3+8=11
11-->1+1=2
so answer is 2
*/
#include <bits/stdc++.h>
using namespace std;
int addDigits(int num)
{
    if (num % 10 == num) // if single digit no then pass it as it is
    {
        return num;
    }
    else
    {
        int sum = 0;
        while (num > 0)
        // find the sum of the digit
        {
            sum += num % 10;
            num = num / 10;
        }
        return addDigits(sum); // check if again for the new number
    }
}
int main()
{
    int num;
    num = 38;
    cout << addDigits(num) << endl;
    return 0;
}