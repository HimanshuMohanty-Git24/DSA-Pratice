#include <bits/stdc++.h>
using namespace std;
int bitwiseComplement(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int m = n;    // taking another variable to implement upon
    int mask = 0; // Creating mask of 000......00000
    while (m != 0)
    {
        mask = (mask << 1) | 1; // creating a ....111 mask according to the no ob bits of the input integer eg. for 5 there are 101 3 bits so we need a mask of 0....0111(32 bit mask)
        m = m >> 1;             // this the loop condition according to which this loop iterate and terminates whenever it gets the last 1 bit of the number
    }
    int ans = (n ^ mask); // we XOR the mask with it eg. 101^111 we get 010-->2 which is the 1's complement of the 5
    return ans;
}
int main()
{
    int ans = bitwiseComplement(7);
    cout << ans;
    return 0;
}