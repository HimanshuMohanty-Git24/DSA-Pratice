#include <bits/stdc++.h>
using namespace std;
int hammingWeight(uint32_t n)
{
    int ctr = 0;   // counter for number of 1 bits
    while (n != 0) // Check if n ==0 that means no 1 present in it anymore so we stop
    {
        if (n & 1) // Checks the last bit is zero or not by anding 1 if last bit is zero it will not eneter the loop
        {
            ctr++;
        }
        n = n >> 1; // Now we move the n toward right to check each bit by bringing it to the last
    }
    return ctr;
}
int main()
{
    int res = hammingWeight(00000000000000000000000000001011);
    cout << res;

    return 0;
}