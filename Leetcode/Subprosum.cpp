/*1281. Subtract the Product and Sum of Digits of an Integer
 */
#include <bits/stdc++.h>
using namespace std;
int subtractProductAndSum(int n)
{
    int sum = 0;
    int pro = 1;
    while (n != 0)
    {
        sum = sum + (n % 10);
        pro = pro * (n % 10);
        n = n / 10;
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
