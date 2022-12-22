/*1281. Subtract the Product and Sum of Digits of an Integer
 */
#include <bits/stdc++.h>
using namespace std;
int subtractProductAndSum(int n)
{
    int sum = 0;
    int pro = 1;
    while (n != 0) // till num is not reduced to zero
    {
        sum = sum + (n % 10); // sum of each digit
        pro = pro * (n % 10); // product of each digit
        n = n / 10;           // reduce the num expression by removing the last part
    }
    int res = pro - sum;
    return res;
}
int main()
{
    int val = subtractProductAndSum(234);
    cout << val;
    return 0;
}
